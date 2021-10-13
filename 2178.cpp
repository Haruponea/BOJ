#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#define x first
#define y second
using namespace std;

int vis[102][102];
int board[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			board[i][j] = (int)(s[j] - '0');
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	vis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
			vis[nx][ny] = vis[cur.x][cur.y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	cout << vis[n - 1][m - 1];
}
