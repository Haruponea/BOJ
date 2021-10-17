#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;

int vis[2][500002]; // 0 is even 1 is odd

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, t = 0;
	cin >> n >> k;
	vis[0][n] = 1;
	queue<pair<int,int>> q;
	q.push({ n,0 });
	while (!q.empty()) {
		pair<int,int> cur = q.front(); q.pop();
		for (int nxt : {cur.x + 1, cur.x - 1, cur.x * 2}) {
			if (nxt < 0 || nxt > 500000)continue;
			if (vis[1-cur.y][nxt] == 0) { //y == 0 means even else odd
				vis[1-cur.y][nxt] = vis[cur.y][cur.x] + 1;
				q.push({ nxt,1-cur.y });
			}
		}
	}
	while (k <= 500000) {
		k += t;
		if (vis[t % 2][k] != 0 && vis[t % 2][k] - 1 <= t) {
			cout << t;
			return 0;
		}
		t++;
	}
	cout << -1;
}
