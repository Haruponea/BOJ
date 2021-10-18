#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int vis[100002]; //0 not visited, 1 visited, 2 circled, 3 not circled
int nxt[100002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> nxt[i];
		for (int i = 1; i <= n; i++) {
			if (vis[i] != 0) continue;
			int cur = i;
			while (true) {
				vis[cur] = 1;
				cur = nxt[cur];
				if (vis[cur] == 2 || vis[cur] == 3) {
					cur = i;
					while (vis[cur] == 1) {
						vis[cur] = 3;
						cur = nxt[cur];
					}
					break;
				}
				if (vis[cur] == 1 && cur != i) {
					while (vis[cur] != 2) {
						vis[cur] = 2;
						cur = nxt[cur];
					}
					cur = i;
					while (vis[cur] != 2) {
						vis[cur] = 3;
						cur = nxt[cur];
					}
					break;
				}
				if (vis[cur] == 1 && cur == i) {
					while (vis[cur] != 2) {
						vis[cur] = 2;
						cur = nxt[cur];
					}
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) if (vis[i] == 3) cnt++;
		cout << cnt<<'\n';
		fill(vis, vis + 100002, 0);
	}
}
