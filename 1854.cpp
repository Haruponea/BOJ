#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n, m, k;
priority_queue<int> dist[1003]; //dist[i]는 1에서 i번째로 가는 k이하 최단거리의 모음
vector<pair<int, int>> edges[1003]; //dist[start].{dest, cost};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	int a, b, c;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//<dist, dest>
	dist[1].push(0);
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curIdx = pq.top().second;
		pq.pop();

		if (!dist[curIdx].empty() && (dist[curIdx].size()>=k && curDist > dist[curIdx].top())) continue;

		for (pair<int, int> next : edges[curIdx]) {
			int nextIdx = next.first;
			int nextCost = next.second;
			if (dist[nextIdx].size() < k) {
				dist[nextIdx].push(curDist + nextCost);
				pq.push({ curDist + nextCost, nextIdx });
			}
			else {
				if (dist[nextIdx].top() < curDist + nextCost) continue;
				dist[nextIdx].pop();
				dist[nextIdx].push(curDist + nextCost);
				pq.push({ curDist + nextCost,nextIdx });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) cout << -1 << '\n';
		else cout << dist[i].top()<<'\n';
	}
	return 0;
}
