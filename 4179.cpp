#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;

int fvis[1002][1002];
int jvis[1002][1002];
char board[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	queue<pair<int, int>> fire;
	queue<pair<int, int>> jihoon;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'J') {
				jihoon.push(make_pair(i, j));
				jvis[i][j] = 1;
			}
			else if (board[i][j] == 'F') {
				fire.push(make_pair(i, j));
				fvis[i][j] = 1;
			}
		}
	}
	while (!fire.empty()) {
		auto cur = fire.front(); fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (fvis[nx][ny] != 0 || board[nx][ny] == '#') continue;
			fvis[nx][ny] = fvis[cur.x][cur.y] + 1;
			fire.push(make_pair(nx, ny));
		}
	}

	while (!jihoon.empty()) {
		auto cur = jihoon.front(); jihoon.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				cout << jvis[cur.x][cur.y];
				return 0;
			}
			if (jvis[nx][ny] != 0 || board[nx][ny] != '.' || (fvis[nx][ny]!= 0 && jvis[cur.x][cur.y] + 1 >= fvis[nx][ny])) continue;
			jihoon.push({ nx, ny });
			jvis[nx][ny] = jvis[cur.x][cur.y] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}
