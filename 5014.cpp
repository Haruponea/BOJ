#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int vis[1000003];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<int> q;
	vis[S] = 1;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == G) {
			cout << vis[G] - 1;
			return 0;
		}
		for (int n : {cur + U, cur - D}) {
			if (n<1 || n>F || vis[n] != 0) continue;
			vis[n] = vis[cur] + 1;
			q.push(n);
		}
	}
	cout << "use the stairs";
}
