#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102][102];
int vis[102][102][102];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 1;
    int m, n, h, z, x, y;
    cin >> m >> n >> h;

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k));
                    vis[i][j][k] = 1;
                }
            }

    while (!q.empty()) {
        tie(z, x, y) = q.front();
        q.pop();
        for (int k = 0; k < 6; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (board[nz][nx][ny] != 0 || vis[nz][nx][ny] != 0)
                continue;
            q.push(make_tuple(nz, nx, ny));
            vis[nz][nx][ny] = vis[z][x][y] + 1;
            ans = max(ans, vis[nz][nx][ny]);
        }
    }

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++) {
                if (vis[i][j][k] == 0 && board[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
    cout << ans - 1;
    return 0;
}
