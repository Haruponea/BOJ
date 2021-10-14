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

	int n,min=9999999;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int label = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0 && vis[i][j] == 0) {
				board[i][j] = label;
				queue<pair<int, int>> q;
				q.push({ i,j });
				vis[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.x + dx[k];
						int ny = cur.y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
						board[nx][ny] = label;
						q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
				label++;
			}
		}
	}
	for (int land = 1; land < label; land++) {
		for (int k = 0; k < 102; k++) fill(vis[k], vis[k] + 102, 0);
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == land) {
					q.push({ i, j });
					vis[i][j] = 1;
				}
			}
		}
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (board[nx][ny] != land && board[nx][ny] != 0) {
					min = (min < vis[cur.x][cur.y] - 1) ? min : vis[cur.x][cur.y] - 1;
					break;
				}
				if (board[nx][ny] != land && vis[nx][ny] == 0) {
					q.push({ nx, ny });
					vis[nx][ny] = vis[cur.x][cur.y] + 1;
				}
			}
		}
	}
	cout << min;
}
