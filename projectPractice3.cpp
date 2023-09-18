#include <iostream>
#include <cstdlib>
#include <random>

// 프로젝트3. 랜덤 숫자 맞추기

using std::cout;
using std::cin;
using std::endl;

int main() {
	int inputNum = 0, num, cnt = 0;
	bool isSame = false;
	int lotto[6] = {}, inNumAry[6] = {};

	std::srand(time(NULL));

	// 1~25 랜덤숫자 발행 (중복X)
	while (cnt < 6) {
		isSame = false;
		num = std::rand() % 25 + 1;
		for (int i = 0; i < cnt; i++) {
			if (lotto[i] == num) {
				//중복 발생.
				isSame = true;
				break;
			}
		}
		if (!isSame) {
			lotto[cnt] = num;
			cnt++;
		}
	}


	// 1~25 6개 숫자입력 (중복X)
	cout << "숫자는 1~25까지의 숫자만 입력할 수 있습니다." << endl;
	cnt = 0;
	while (cnt < 6) {
		isSame = false;
		cout << cnt + 1 << "번째 숫자를 입력하세요 : ";
		cin >> inputNum;
		if (inputNum > 25 || inputNum < 1) {
			cout << "잘못된 숫자입니다. 다시 입력해주세요." << endl;
		}
		else {
			for (int i = 0; i < cnt; i++) {
				if (inNumAry[i] == inputNum) {
					//중복 발생.
					cout << "이미 입력된 숫자입니다." << endl;
					isSame = true;
					break;
				}
			}
			if (!isSame) {
				inNumAry[cnt] = inputNum;
				cnt++;
			}
		}
	}


	cout << "\n--------------------------------------" << endl;
	cout << "당첨번호 공개 !" << endl;
	int sameCnt = 0;
	for (int i = 0; i < 6; i++) {
		cout << lotto[i] << " ";

		for (int j = 0; j < 6; j++) {
			if (lotto[i] == inNumAry[j]) {
				sameCnt++;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << inNumAry[i] << " ";
	}

	// 6개 모두 맞추면 1등, ..., 한 개도 맞추지 못하면 7등
	cout << "\n1 ~ 7등까지 결과가 나올 수 있습니다." << endl;
	cout << "결과 : "<< (7- sameCnt) << "등 입니다 !" << endl;

}