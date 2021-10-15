#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#define x first
#define y second

using namespace std;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int board[32][32][32];
int vis[32][32][32];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int L = 1, R, C;
	tuple<int, int, int> ex;
	while (L != 0) {
		queue<tuple<int, int, int>> q;
		cin >> L >> R >> C;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string s;
				cin >> s;
				for (int k = 0; k < C; k++) {
					board[i][j][k] = s[k];
					if (board[i][j][k] == 'S') {
						q.push(make_tuple(i, j, k));
						vis[i][j][k] = 1;
					}
					else if (board[i][j][k] == 'E') {
						ex = make_tuple(i, j, k);
					}
				}
			}
		}
		bool possible = false;
		while (!q.empty()) {
			tuple<int, int, int> cur = q.front(); q.pop();
			if (cur == ex) {
				cout << "Escaped in " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] - 1 << " minute(s).\n";
				possible = true;
				break;
			}
			for (int dir = 0; dir < 6; dir++) {
				int nz = get<0>(cur) + dz[dir];
				int nx = get<1>(cur) + dx[dir];
				int ny = get<2>(cur) + dy[dir];
				if (nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= R || ny >= C) continue;
				if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] != 0) continue;
				q.push(make_tuple(nz, nx, ny));
				vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			}
		}
		if (!possible && L != 0)
			cout << "Trapped!\n";

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				fill(vis[i][j], vis[i][j] + C, 0);
			}
		}
	}
}
