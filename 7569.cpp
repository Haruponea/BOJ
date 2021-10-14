#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include<tuple>
#define x first
#define y second

using namespace std;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int board[102][102][102];
int vis[102][102][102];
queue<tuple<int, int, int>> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, h;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					vis[i][j][k] = 1;
				}
				else if (board[i][j][k] == -1) {
					vis[i][j][k] = -1;
				}
			}
		}
	}
	while (!q.empty()) {
		int curx, cury, curz;
		tie(curz, curx, cury) = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = curz + dz[i];
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || nz >= h || ny >= m) continue;
			if (board[nz][nx][ny] != 0 || vis[nz][nx][ny] != 0) continue;
			vis[nz][nx][ny] = vis[curz][curx][cury] + 1;
			q.push(make_tuple(nz, nx, ny));
		}
	}
	int mx = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (vis[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				else if (vis[i][j][k] > 0)
					mx = (mx < vis[i][j][k]) ? vis[i][j][k] : mx;
			}
		}
	}
	cout << mx-1;
}
