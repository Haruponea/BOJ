#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second

using namespace std;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int vis[302][302];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		int n;
		cin >> n;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		q.push({ x1,y1 });
		vis[x1][y1] = 1;
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (vis[nx][ny] != 0) continue;
				vis[nx][ny] = vis[cur.x][cur.y] + 1;
				q.push({ nx,ny });
			}
		}
		cout << vis[x2][y2] - 1<<'\n';
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + 302, false);
		}
	}
}
