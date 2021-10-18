#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#define x first
#define y second
using namespace std;

int dx1[4] = { 1,-1,0,0 };
int dy1[4] = { 0,0,1,-1 };
int dx2[8] = { 2,2,1,1,-1,-1,-2,-2 };
int dy2[8] = { 1,-1,2,-2,2,-2,1,-1 };
int board[202][202];
int vis[202][202][32];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> k >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	vis[0][0][0] = 1;
	while (!q.empty()) {
		int curx, cury, cnt;
		tie(curx, cury, cnt) = q.front(); q.pop();
		if (curx == n - 1 && cury == m - 1) {
			cout << vis[curx][cury][cnt] - 1;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx1[i];
			int ny = cury + dy1[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 0 && vis[nx][ny][cnt] == 0) {
				q.push({ nx,ny,cnt });
				vis[nx][ny][cnt] = vis[curx][cury][cnt] + 1;
			}
		}
		for (int i = 0; i < 8; i++) {
			int nx = curx + dx2[i];
			int ny = cury + dy2[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 0 && cnt<k && vis[nx][ny][cnt + 1] == 0) {
				q.push({ nx,ny,cnt + 1 });
				vis[nx][ny][cnt + 1] = vis[curx][cury][cnt] + 1;
			}
		}
	}
	cout << -1;
}
