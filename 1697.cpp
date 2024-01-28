#include <bits/stdc++.h>
using namespace std;

int dist[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist + 100002, -1);
    int n, m;
    cin >> n >> m;
    if (n == m)
        cout << 0;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int next[3] = {cur - 1, cur + 1, cur * 2};
        for (int i = 0; i < 3; i++) {
            if (next[i] < 0 || next[i] > 100000)
                continue;
            if (dist[next[i]] != -1)
                continue;
            if (next[i] == m) {
                cout << dist[cur] + 1;
                return 0;
            }
            dist[next[i]] = dist[cur] + 1;
            q.push(next[i]);
        }
    }
}
