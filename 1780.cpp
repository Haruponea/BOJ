#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[2200][2200];
int cnt[3];

bool possible(int n, int x, int y) {
	int cur = board[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (cur != board[i][j])
				return false;
		}
	}
	return true;
}

void solve(int n, int x, int y) {
	if (n == 1) {
		cnt[board[x][y] + 1]++;
		return;
	}
	if(possible(n, x, y)){
		cnt[board[x][y] + 1]++;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(n / 3, x + i * (n / 3), y + j * (n / 3));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> board[i][j];
	solve(n, 0, 0);
	for (int ans : cnt)
		cout << ans << '\n';
}
