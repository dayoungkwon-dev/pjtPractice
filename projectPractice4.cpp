#include <iostream>
#include <vector>


// 프로젝트4. 마방진 만들기

using namespace std;

int main() {
	// 홀수 n입력받아 n*n 마방진 생성.
	int n, row, col;
	int newRow, newCol;

	cout << "마방진의 행 혹은 열의 수를 홀수로 입력해주세요 : ";
	cin >> n;

	if (n % 2 == 0) {
		cout << "홀수만 가능합니다." << endl;
	}
	else {
		vector <vector<int>> mbj(n, vector<int>(n));

		// 1은 첫 행의 가운데 위치.
		row = 0;
		col = (n / 2);
		mbj[row][col] = 1;

		for (int num = 2; num <= n * n; num++) {
			// 우상단으로 숫자 +1씩 늘어남.
			newRow = row - 1;
			newCol = col + 1;
			if (newRow < 0) {
				newRow = n - 1;
			}
			if (newCol > n - 1) {
				newCol = 0;
			}

			if (mbj[newRow][newCol] != 0) {
				row++;
				if (row > n - 1) {
					row = 0;
				}
			}
			else {
				row = newRow;
				col = newCol;
			}
			mbj[row][col] = num;
		}


		// 결과 출력.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mbj[i][j] << " ";
			}
			cout << endl;
		}
	}
}