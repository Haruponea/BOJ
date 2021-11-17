#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,ans=99999999;
bool connected[12][12];
int p[12];

bool bfs(int idx, int team, vector<int> brute, int teamnum) {
    bool vis[12];
    int cnt = 0;
    fill(vis, vis + 12, false);
    queue<int> q;
    q.push( idx );
    vis[idx] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < n; i++) {
            if (connected[cur][i] == false)continue;
            if (brute[i] != team || vis[i]==true) continue;
            q.push(i);
            vis[i] = true;
        }
    }
    if (cnt == teamnum) return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            connected[i][a-1] = true;
            connected[a-1][i] = true;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        vector<int> brute(n, 0);
        fill(brute.begin() + n - i, brute.end(), 1);
        int area1 = -1, area2 = -1;
        do {
            for (int k = 0; k < n; k++) {
                if (brute[k] == 0) area1 = k;
                else area2 = k;
            }
            if (bfs(area1, 0,brute, n-i) && bfs(area2, 1,brute,i)) {
                int p1 = 0, p2 = 0;
                for (int k = 0; k < n; k++) {
                    if (brute[k] == 0) p1 += p[k];
                    else p2 += p[k];
                }
                ans = min(ans, abs(p1 - p2));
            }
        } while (next_permutation(brute.begin(), brute.end()));
    }
    if (ans == 99999999) cout << -1;
    else cout << ans;
}
