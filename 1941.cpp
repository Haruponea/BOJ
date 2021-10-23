#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ans, S;
vector<string> s;
pair<int, int> st;
bool vis[6][6];
int board[6][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void func(int level, int idx) {
	if (level == 7) {
		queue<pair<int, int>> q;
		q.push({ idx / 5, idx % 5 });
		vis[idx / 5][idx % 5] = true;
		int len = 1;
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
				if (vis[nx][ny] == true || board[nx][ny] != 1) continue;
				vis[nx][ny] = true;
				len++;
				q.push({ nx,ny });
			}
		}
		if (S >= 4 && len == 7) {
			ans++;
		}
		for(int i = 0; i < 6; i++) {
			fill(vis[i], vis[i] + 6, false);
		}
		return;
	}
	for (int i = idx + 1; i < 25; i++) {
		board[i / 5][i % 5] = 1;
		if (s[i / 5][i % 5] == 'S') S++;
		func(level + 1, i);
		board[i / 5][i % 5] = 0;
		if (s[i / 5][i % 5] == 'S') S--;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 5; i++) {
		string st;
		cin >> st;
		s.push_back(st);
	}
	func(0, -1);
	cout << ans;
}
