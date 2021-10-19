#include <iostream>
#include <algorithm>
using namespace std;

int n;
char board[2200][2200];
void star(int n,int x, int y) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					board[x + i][y + j] = ' ';
				else
					board[x + i][y + j] = '*';
			}
		}
	}
	else {
		int d = n / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) {
					for (int m = 0; m < d; m++) {
						for (int q = 0; q < d; q++) {
							board[x + d + m][y + d + q] = ' ';
						}
					}
					continue;
				}
				star(d, x + i * d, y + j * d);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}
