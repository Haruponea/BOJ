#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;

int vis[1002][1002];
int board[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, mx = 1;
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				vis[i][j] = 1;
			}
			else if (board[i][j] == -1) {
				vis[i][j] = -1;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny] != 0 || board[nx][ny] == -1) continue;
			vis[nx][ny] = vis[cur.x][cur.y] + 1;
			q.push({ nx, ny });
			mx = (mx > vis[nx][ny]) ? mx : vis[nx][ny];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << mx - 1;
}
