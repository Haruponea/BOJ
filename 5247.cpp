#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int fvis[1002][1002];
int pvis[1002][1002];
char board[1002][1002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		bool possible = false;
		queue<pair<int, int>> person;
		queue<pair<int, int>> fire;
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				board[i][j] = s[j];
				if (board[i][j] == '@') {
					person.push({ i,j });
					pvis[i][j] = 1;
				}
				else if (board[i][j] == '*') {
					fire.push({ i,j });
					fvis[i][j] = 1;
				}
			}
		}

		while (!fire.empty()) {
			pair<int, int> cur = fire.front(); fire.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == '#' || fvis[nx][ny] != 0) continue;
				fire.push({ nx,ny });
				fvis[nx][ny] = fvis[cur.x][cur.y] + 1;
			}
		}

		while (!person.empty()) {
			pair<int, int> cur = person.front(); person.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
					cout << pvis[cur.x][cur.y] << '\n';
					possible = true;
					break;
				}
				if (board[nx][ny] == '#' || pvis[nx][ny] != 0 || (fvis[nx][ny]!=0 && pvis[cur.x][cur.y]+1 >= fvis[nx][ny])) continue;
				person.push({ nx,ny });
				pvis[nx][ny] = pvis[cur.x][cur.y] + 1;
			}
			if (possible) break;
		}
		if(!possible)
			cout << "IMPOSSIBLE\n";
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(fvis[i], fvis[i] + m, 0);
			fill(pvis[i], pvis[i] + m, 0);
		}
	}
}
