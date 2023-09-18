#include <iostream>
#include <cstdlib>
#include <random>

// ������Ʈ3. ���� ���� ���߱�

using std::cout;
using std::cin;
using std::endl;

int main() {
	int inputNum = 0, num, cnt = 0;
	bool isSame = false;
	int lotto[6] = {}, inNumAry[6] = {};

	std::srand(time(NULL));

	// 1~25 �������� ���� (�ߺ�X)
	while (cnt < 6) {
		isSame = false;
		num = std::rand() % 25 + 1;
		for (int i = 0; i < cnt; i++) {
			if (lotto[i] == num) {
				//�ߺ� �߻�.
				isSame = true;
				break;
			}
		}
		if (!isSame) {
			lotto[cnt] = num;
			cnt++;
		}
	}


	// 1~25 6�� �����Է� (�ߺ�X)
	cout << "���ڴ� 1~25������ ���ڸ� �Է��� �� �ֽ��ϴ�." << endl;
	cnt = 0;
	while (cnt < 6) {
		isSame = false;
		cout << cnt + 1 << "��° ���ڸ� �Է��ϼ��� : ";
		cin >> inputNum;
		if (inputNum > 25 || inputNum < 1) {
			cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
		}
		else {
			for (int i = 0; i < cnt; i++) {
				if (inNumAry[i] == inputNum) {
					//�ߺ� �߻�.
					cout << "�̹� �Էµ� �����Դϴ�." << endl;
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
	cout << "��÷��ȣ ���� !" << endl;
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

	// 6�� ��� ���߸� 1��, ..., �� ���� ������ ���ϸ� 7��
	cout << "\n1 ~ 7����� ����� ���� �� �ֽ��ϴ�." << endl;
	cout << "��� : "<< (7- sameCnt) << "�� �Դϴ� !" << endl;

}