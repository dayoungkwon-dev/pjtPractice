#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>


// ������Ʈ2. Ÿ�Ӿ��� �����ձ� ����

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	int check[100] = { 0, };
	int arySize = 0, nextWdSize = 0;
	bool chkSame;
	string beforeWord, nextWord;
	std::vector<string> wordArray[100];
	clock_t startTime = clock();

	wordArray->push_back("apple");

	while (1) {
		chkSame = false;
		arySize = wordArray->size();
		for (int i = 0; i < arySize; i++) {
			cout << wordArray->at(i);
			if (i == wordArray->size() - 1) {
				cout << endl;
			}
			else {
				cout << "->";
			}
		}
		cout << "\n���� �ܾ �Է��ϼ��� : ";
		cin >> nextWord;


		// ���ѽð� check !!
		clock_t endTime = clock();
		// ���ѽð� 30��
		if ((endTime - startTime) / CLOCKS_PER_SEC >= 30) {
			cout << "Ÿ�ӿ��� !" << endl;
			break;
		}

		arySize = wordArray->size();
		beforeWord = wordArray->at(arySize - 1);
		int size = beforeWord.size();

		// �����ܾ� ������ ���ڿ� �����ܾ� ó�� ���� ��ġ ���� Ȯ��.
		if (beforeWord[size-1] == nextWord[0]) {
			//�ߺ�üũ
			for (int i = 0; i < arySize; i++) {
				if (nextWord == wordArray->at(i)){
					chkSame = true;
				}
			}

			if (chkSame) {
				cout << "�ߺ��� �ܾ��Դϴ�." << endl;
			}
			else {
				wordArray->push_back(nextWord);
			}
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	cout << "\n���� ���� !" << endl;
	cout << "�� �Է��� �ܾ� ���� : " << wordArray->size() << endl;
}