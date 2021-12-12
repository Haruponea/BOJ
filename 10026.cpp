#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int R, G, B, RG, n;
char board[102][102];

void bfs1(char target, int& t) {
	queue<pair<int, int>> q;
	int vis[102][102];
	for (int i = 0; i < 102; i++) {
		fill(vis[i], vis[i] + 102, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == target && vis[i][j] == 0) {
				t++;
				q.push({ i, j });
				vis[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.x + dx[i];
						int ny = cur.y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (board[nx][ny] != target || vis[nx][ny] != 0) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}
}

void bfs2(int& t) {
	queue<pair<int, int>> q;
	int vis[102][102];
	for (int i = 0; i < 102; i++) {
		fill(vis[i], vis[i] + 102, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((board[i][j] == 'R' || board[i][j] == 'G' ) && vis[i][j] == 0) {
				t++;
				q.push({ i, j });
				vis[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.x + dx[i];
						int ny = cur.y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (board[nx][ny] == 'B' || vis[nx][ny] != 0) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
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
			board[i][j] = s[j];
		}
	}
	bfs1('R', R);
	bfs1('G', G);
	bfs1('B', B);
	bfs2(RG);
	cout << R + G + B << ' ' << RG + B;
}
