#include <iostream>
#include <vector>


// ������Ʈ4. ������ �����

using namespace std;

int main() {
	// Ȧ�� n�Է¹޾� n*n ������ ����.
	int n, row, col;
	int newRow, newCol;

	cout << "�������� �� Ȥ�� ���� ���� Ȧ���� �Է����ּ��� : ";
	cin >> n;

	if (n % 2 == 0) {
		cout << "Ȧ���� �����մϴ�." << endl;
	}
	else {
		vector <vector<int>> mbj(n, vector<int>(n));

		// 1�� ù ���� ��� ��ġ.
		row = 0;
		col = (n / 2);
		mbj[row][col] = 1;

		for (int num = 2; num <= n * n; num++) {
			// �������� ���� +1�� �þ.
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


		// ��� ���.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mbj[i][j] << " ";
			}
			cout << endl;
		}
	}
}