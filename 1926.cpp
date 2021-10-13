#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#define X first
#define Y second
using namespace std;

int vis[502][502];
int board[502][502];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int cnt = 0, max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) v.push_back(make_pair(i, j));
		}
	}
	queue<pair<int, int>> q;
	while (!v.empty()) {
		pair<int, int> start = v.back(); v.pop_back();
		if (vis[start.X][start.Y] == true) continue;
		else {
			int cur_size = 0;
			vis[start.X][start.Y] = true;
			queue<pair<int, int>> q;
			q.push(start);
			cur_size += 1;
			cnt += 1;
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (vis[nx][ny] == true || board[nx][ny] == 0) continue;
					cur_size += 1;
					q.push(make_pair(nx, ny));
					vis[nx][ny] = true;
				}
			}
			max = (max > cur_size) ? max : cur_size;
		}
	}
	cout << cnt << '\n' << max;
}
