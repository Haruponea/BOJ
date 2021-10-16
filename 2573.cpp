#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second

using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int board[302][302];
bool vis[302][302];

bool exist(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0)
				return true;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, ans = 0;
	bool possible = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	do {
		queue<pair<int, int>> q;
		int cnt = 0;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && vis[i][j] == false) {
					q.push({ i,j });
					cnt += 1;
					vis[i][j] = true;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.x + dx[dir];
							int ny = cur.y + dy[dir];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
							if (board[nx][ny] == 0) {
								v.push_back(cur);
							}
							if (board[nx][ny] == 0 || vis[nx][ny] == true)continue;
							q.push({ nx,ny });
							vis[nx][ny] = true;
						}
					}
				}
			}
		}
		if (cnt > 1) {
			possible = true;
			break;
		}
		for (auto cur : v) {
			if(board[cur.x][cur.y]>0)
				board[cur.x][cur.y]--;
		}
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + m, false);
		}
		ans += 1;
	} while (exist(n,m));

	if (possible) cout << ans;
	else cout << 0;
}
