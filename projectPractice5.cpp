#include <iostream>
#include <time.h>
#include <random>


// ������Ʈ5. �߱� ����


using std::cout;
using std::cin;
using std::endl;

int main() {
	int num1, num2, num3, num;
	int comNum[3] = { 0, }, inNum[3] = { 0, }, check[10] = { 0, };
	int strike = 0, ball = 0, playCnt = 0;
	cout << "�߱� ����" << endl;

	std::srand(time(NULL));
	for(int i=0; i< 3; i++){
		do{ 
			num = std::rand() % 9 + 1;
		} while (check[num] == 1);
		comNum[i] = num;
		check[num] = 1;

		cout << "�ӽ� : " << comNum[i] << endl;
	}
	

	while (1) {
		cout << "1 ~ 9 ������ ���� 3���� �Է� �Ͻÿ�. (�̿��� ���� : ����)" << endl;
		cin >> num1 >> num2 >> num3;

		//�ߺ�üũ
		if (num1 == num2 || num2 == num3 || num1 == num3) {
			cout << "�ߺ� ���ڰ� �ֽ��ϴ�." << endl;
		}else if (num1 < 1 || num2 < 1 || num3 < 1 || num1 > 9 || num2 > 9 || num3 > 9) {
			cout << "������ �����Ͽ����ϴ�." << endl;
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
				cout << playCnt << "�� ���� ���߼̽��ϴ�." << endl;
				break;
			}
			else {
				cout << "Strike : " << strike << "     Ball : " << ball << endl;
			}
			playCnt++;
		}
	}
}