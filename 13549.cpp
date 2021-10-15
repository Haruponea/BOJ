#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int vis[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vis[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) {
			cout << vis[k] - 1;
			break;
		}
		int tmp = cur*2;
		while (cur != 0 && tmp < 100001) {
			if (vis[tmp] == 0) {
				q.push(tmp);
				vis[tmp] = vis[cur];
			}
			tmp *= 2;
		}
		for (int nx : {cur - 1, cur + 1}) {
			if (nx < 0 || nx>100000) continue;
			if (vis[nx] != 0) continue;
			vis[nx] = vis[cur] + 1;
			q.push(nx);
		}
	}
}
