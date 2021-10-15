#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int board[102][102];
int vis[102][102];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans = 0, max_h=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			max_h = (max_h < board[i][j]) ? board[i][j] : max_h;
		}
	}
	
	for (int rain = 0; rain < max_h; rain++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] <= rain || vis[i][j] != 0) continue;
				cnt += 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				vis[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (board[nx][ny] <= rain || vis[nx][ny] != 0) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		ans = (ans < cnt) ? cnt : ans;
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + n, 0);
		}
	}
	cout << ans;
}
