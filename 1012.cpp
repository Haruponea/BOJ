#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs(int board[][52], int vis[][52], int n, int m, int k) {
	queue<pair<int, int>> q;
	int cnt = 0;
	while (k--) {
		int x, y;
		cin >> x >> y;
		board[y][x] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				q.push({ i, j });
				vis[i][j] = 1;
				cnt += 1;
			}
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (vis[nx][ny] == 1 || board[nx][ny] == 0)continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int board[52][52];
		int vis[52][52];
		for (int i = 0; i < 52; i++) fill(board[i], board[i] + 52, 0);
		for (int i = 0; i < 52; i++) fill(vis[i], vis[i] + 52, 0);
		int m, n, k;
		cin >> m >> n >> k;
		cout << bfs(board, vis, n, m, k)<<'\n';
	}
}
