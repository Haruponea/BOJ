#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[52][52];
int vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x, y, ans = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < 52; i++) {
            fill(board[i], board[i] + 52, 0);
            fill(vis[i], vis[i] + 52, 0);
        }
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && vis[i][j] == 0) {
                    queue<pair<int, int>> q;
                    ans++;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int l = 0; l < 4; l++) {
                            int nx = cur.X + dx[l];
                            int ny = cur.Y + dy[l];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;
                            if (board[nx][ny] == 0 || vis[nx][ny] == 1)
                                continue;
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
