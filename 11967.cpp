#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#define x first
#define y second
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board[102][102];
bool vis[102][102];
vector<pair<int, int>> light[102][102];
int ans = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	board[0][0] = 1;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		light[x-1][y-1].push_back({ a-1, b-1 });
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (pair<int, int> next : light[cur.x][cur.y]) {
			if (board[next.x][next.y] == 0) {
				ans += 1;
				board[next.x][next.y] = 1;
				for (int i = 0; i < 4; i++) {
					int nx = next.x + dx[i];
					int ny = next.y + dy[i];
					if (nx < 0 || ny<0 || nx>=n || ny >= n) continue;
					if (board[nx][ny] == 1 && vis[nx][ny] != 0) {
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (board[nx][ny] == 1 && vis[nx][ny] == 0) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
	cout << ans;
}
