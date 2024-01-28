#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int ans = 0, cnt = 0, temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 1 && vis[i][j] == false) {
                temp = 1;
                cnt += 1;
                vis[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (vis[nx][ny] == true || board[nx][ny] == 0)
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                        temp += 1;
                    }
                }
                ans = max(ans, temp);
            }
    cout << cnt << "\n" << ans;
}
