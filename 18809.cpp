#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, G, R, ans, possiblelen;
int board[52][52];
int vis1[52][52];
int vis2[52][52];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> possible;
vector<pair<int, int>> Rstart;
vector<pair<int, int>> Gstart;

void func(int idx, int R, int G) {
	if (R == 0 && G == 0) {
		int cnt = 0;
		queue<pair<int, int>> q1;
		for (int i = 0; i < Gstart.size(); i++) {
			q1.push(Gstart[i]);
			vis1[Gstart[i].first][Gstart[i].second] = 1;
		}
		queue<pair<int, int>> q2;
		for (int i = 0; i < Rstart.size(); i++) {
			q2.push(Rstart[i]);
			vis2[Rstart[i].first][Rstart[i].second] = 1;
		}
		while (!q1.empty() || !q2.empty()) {
			queue<pair<int, int>> nextq1;
			queue<pair<int, int>> nextq2;
			while (!q1.empty()) {
				pair<int, int> cur = q1.front(); q1.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (vis1[nx][ny] != 0 || board[nx][ny] == 0)continue;
					vis1[nx][ny] = vis1[cur.first][cur.second] + 1;
					nextq1.push({ nx,ny });
				}
			}
			while (!q2.empty()) {
				pair<int, int> cur = q2.front(); q2.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (vis2[nx][ny] != 0 || board[nx][ny] == 0) continue;
					if (vis1[nx][ny] == vis2[cur.first][cur.second] + 1) {
						vis2[nx][ny] = -1;
						cnt++;
						continue;
					}
					nextq2.push({ nx,ny });
					vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
				}
			}
			while (!nextq1.empty()) {
				pair<int, int> cur = nextq1.front(); nextq1.pop();
				if (vis2[cur.first][cur.second] == -1) continue;
				q1.push(cur);
			}
			q2 = nextq2;
		}
		ans = max(ans, cnt);
		for (int i = 0; i < 52; i++) {
			fill(vis1[i], vis1[i] + 52, 0);
			fill(vis2[i], vis2[i] + 52, 0);
		}
		return;
	}
	for (int i = idx + 1; i < possiblelen; i++) {
		if (R > 0) {
			Rstart.push_back(possible[i]);
			func(i, R - 1, G);
			Rstart.pop_back();
		}
		if (G > 0) {
			Gstart.push_back(possible[i]);
			func(i, R, G - 1);
			Gstart.pop_back();
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> G >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) 
				possible.push_back({ i,j });
		}
	}
	possiblelen = possible.size();
	func(-1, R, G);
	cout << ans;
}
