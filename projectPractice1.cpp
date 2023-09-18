#include <iostream>
#include <cstdlib>


// 프로젝트1. 베스킨라빈스31게임

using std::cin;
using std::cout;
using std::endl;

std::string playGame();

int main()
{
    std::string winner;
    std::srand(time(NULL));

    winner = playGame();
    cout << "\n게임 종료 !!" << winner <<"의 승리입니다." << endl;
}

std::string playGame() {
    int num = 0, userNum, comNum;
    std::string win;

    while (1) {
        cout << "개수를 입력하세요 : ";
        cin >> userNum;

        if (1 <= userNum && 3 >= userNum) {
            cout << "사용자가 부른 숫자 !" << endl;
            for (int i = 0; i < userNum; i++) {
                num++;
                cout << num << endl;
                if (num == 31) {
                    win = "컴퓨터";
                    return win;
                }
            }

            //컴퓨터 1~3 랜덤 숫자 선택.
            comNum = std::rand() % 3 + 1;
            cout << "컴퓨터가 부른 숫자 !" << endl;
            for (int j = 0; j < comNum; j++) {
                num++;
                cout << num << endl;
                if (num == 31) {
                    win = "사용자";
                    return win;
                }
            }
            cout << endl;
        }
        else {
            cout << "1~3 사이의 수를 입력해주세요." << endl;
        }
    }
}