#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <climits>

using namespace std;

int depth[100005];
int N,M;
vector<int> v[100005];
bool vis[100005];
int p[18][100005]; //p[i][j]는 j노드의 2^i번쨰 조상

int lca(int a, int b) {
	if (depth[a] > depth[b]) {//b is deeper than a
		swap(a, b);
	}
	for (int i = 17; i >= 0; i--) {
		if ((depth[b] - depth[a]) >= (1 << i))
			b = p[i][b];
	}
	if (a == b) return a;
	else {
		for (int i = 17; i >= 0; i--) {
			if (p[i][a] != p[i][b]) {
				a = p[i][a];
				b = p[i][b];
			}
		}
		return p[0][a];
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	vis[1] = true;
	depth[1] = 0;

	while (!q.empty()) {//set depth
		int cur = q.front(); q.pop();
		for (int nx : v[cur]) {
			if (vis[nx]) continue;
			q.push(nx);
			depth[nx] = depth[cur] + 1;
			vis[nx]=true;
			p[0][nx] = cur;
		}
	}
	
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b)<<'\n';
	}
}
