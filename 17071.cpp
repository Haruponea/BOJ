#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#define x first
#define y second
using namespace std;
int vis[2][500002]; // 0 is even 1 is odd

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, t = 0;
    cin >> n >> k;
    for (int i = 0; i < 2; i++) {
        fill(vis[i], vis[i] + 500002, -1);
    }
    vis[0][n] = 0;
    queue<pair<int, int>> q;
    q.push({ n,0 });
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int nxt : {cur.x * 2, cur.x + 1, cur.x - 1}) {
            if (nxt < 0 || nxt >500000) continue;
            if (vis[(cur.y+1)%2][nxt] != -1) continue;
            vis[(cur.y+1)%2][nxt] = cur.y + 1;
            q.push({ nxt,cur.y + 1 });
        }
    }
    while (k <= 500000) {
        if (vis[t % 2][k] <= t) {
            cout << t;
            return 0;
        }
        k += ++t;
    }
    cout << -1;
}
