#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#define x first
#define y second

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int board[27][27];
int vis[27][27];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = (int)(s[j] - '0');
		}
	}
	vector<int> ans;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 || vis[i][j] != 0) continue;
			cnt++;
			int size = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis[i][j] = 1;
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (board[nx][ny] == 0 || vis[nx][ny] != 0)continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
					size += 1;
				}
			}
			ans.push_back(size);
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (int s : ans)
		cout << s << '\n';
}
