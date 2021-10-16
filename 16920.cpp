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
int board[1002][1002];
int n, m, k;
vector <queue<pair<int, int>>> v;
int s[9];
int ans[9];

bool check() {
	for (int i = 0; i < k; i++) {
		if (!v[i].empty())
			return true;
	}
	return false;
}
void bfs(int player, int s) {
	for (int i = 0; i < s; i++) {
		vector<pair<int, int>> next;
		while (!v[player].empty()) {
			pair<int, int> cur = v[player].front(); v[player].pop();
			for (int j = 0; j < 4; j++) {
				int nx = cur.x + dx[j];
				int ny = cur.y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
				if (board[nx][ny] == '.') {
					board[nx][ny] = player;
					ans[player] += 1;
					next.push_back({ nx,ny });
				}
			}
		}
		if (!next.empty())
			for (auto nx : next)
				v[player].push(nx);
		else
			break;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> s[i];
		queue<pair<int, int>> q;
		v.push_back(q);
	}
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < m; j++) {
			if (st[j] == '.' || st[j] == '#') board[i][j] = st[j];
			else {
				board[i][j] = st[j] - '1';
				v[board[i][j]].push({ i,j });
				ans[board[i][j]] += 1;
			}
		}
	}
	while (check()) {
		for (int player = 0; player < k; player++) {
			bfs(player, s[player]);
		}
	}

	for (int a=0; a < k; a++)
		cout << ans[a] << ' ';
}
