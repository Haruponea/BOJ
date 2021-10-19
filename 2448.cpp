#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int MX = 3 * 1024;
char board[MX][MX*2+1];
void star(int n,int x, int y) {
	if (n == 3) {
		board[x][y + 2] = '*';
		board[x + 1][y + 1] = '*';
		board[x + 1][y + 3] = '*';
		for (int i = 0; i < 5; i++) {
			board[x + 2][y + i] = '*';
		}
	}
	else {
		int d = n / 2;
		star(d, x, y+d);
		star(d, x + d, y);
		star(d, x + d, y + n);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + n * 2, ' ');
	}
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}
