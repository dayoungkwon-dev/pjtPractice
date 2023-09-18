#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>


// 프로젝트2. 타임어택 끝말잇기 게임

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
		cout << "\n다음 단어를 입력하세요 : ";
		cin >> nextWord;


		// 제한시간 check !!
		clock_t endTime = clock();
		// 제한시간 30초
		if ((endTime - startTime) / CLOCKS_PER_SEC >= 30) {
			cout << "타임오버 !" << endl;
			break;
		}

		arySize = wordArray->size();
		beforeWord = wordArray->at(arySize - 1);
		int size = beforeWord.size();

		// 이전단어 마지막 문자와 다음단어 처음 문자 일치 여부 확인.
		if (beforeWord[size-1] == nextWord[0]) {
			//중복체크
			for (int i = 0; i < arySize; i++) {
				if (nextWord == wordArray->at(i)){
					chkSame = true;
				}
			}

			if (chkSame) {
				cout << "중복된 단어입니다." << endl;
			}
			else {
				wordArray->push_back(nextWord);
			}
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
	}
	cout << "\n게임 종료 !" << endl;
	cout << "총 입력한 단어 개수 : " << wordArray->size() << endl;
}