#include <iostream>
#include <time.h>
#include <random>


// 프로젝트5. 야구 게임


using std::cout;
using std::cin;
using std::endl;

int main() {
	int num1, num2, num3, num;
	int comNum[3] = { 0, }, inNum[3] = { 0, }, check[10] = { 0, };
	int strike = 0, ball = 0, playCnt = 0;
	cout << "야구 게임" << endl;

	std::srand(time(NULL));
	for(int i=0; i< 3; i++){
		do{ 
			num = std::rand() % 9 + 1;
		} while (check[num] == 1);
		comNum[i] = num;
		check[num] = 1;

		cout << "임시 : " << comNum[i] << endl;
	}
	

	while (1) {
		cout << "1 ~ 9 사이의 숫자 3개를 입력 하시오. (이외의 숫자 : 종료)" << endl;
		cin >> num1 >> num2 >> num3;

		//중복체크
		if (num1 == num2 || num2 == num3 || num1 == num3) {
			cout << "중복 숫자가 있습니다." << endl;
		}else if (num1 < 1 || num2 < 1 || num3 < 1 || num1 > 9 || num2 > 9 || num3 > 9) {
			cout << "게임을 종료하였습니다." << endl;
			break;
		}
		else {
			inNum[0] = num1;
			inNum[1] = num2;
			inNum[2] = num3;
			strike = 0;
			ball = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (comNum[i] == inNum[j]) {
						if (i == j) {
							strike++;
						}
						else {
							ball++;
						}
					}
				}
			}
			
			if (strike == 3) {
				cout << playCnt << "번 만에 맞추셨습니다." << endl;
				break;
			}
			else {
				cout << "Strike : " << strike << "     Ball : " << ball << endl;
			}
			playCnt++;
		}
	}
}