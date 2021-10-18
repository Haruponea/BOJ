#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#define x first
#define y second
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board[1002][1002];
int vis[1002][1002][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = (int)(s[j] - '0');
		}
	}
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,1 });
	vis[0][0][1] = 1;
	while (!q.empty()) {
		int curx, cury, can_break;
		tie(curx, cury, can_break) = q.front(); q.pop();
		if (curx == n - 1 && cury == m - 1) {
			cout << vis[curx][cury][can_break]; return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 0 && vis[nx][ny][can_break] == 0) {
				vis[nx][ny][can_break] = vis[curx][cury][can_break] + 1;
				q.push({ nx,ny,can_break });
			}
			if (board[nx][ny] == 1 && can_break == 1 && vis[nx][ny][0] == 0) {
				q.push({ nx,ny,0 });
				vis[nx][ny][0] = vis[curx][cury][can_break] + 1;
			}
		}
	}
	cout << -1;
}
