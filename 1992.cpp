#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[65][65];
bool possible(int n, int x, int y) {
	int cur = board[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] != cur) {
				return false;
			}
		}
	}
	return true;
}
void solve(int n, int x, int y) {
	if (n == 1) {
		cout << board[x][y];
		return;
	}
	if (possible(n, x, y)) {
		cout << board[x][y];
	}
	else {
		cout << '(';
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(n / 2, x + i * (n / 2), y + j * (n / 2));
			}
		}
		cout << ')';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j] - '0';
		}
	}
	solve(n, 0, 0);
}
