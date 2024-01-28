#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int vis[2][1002][1002]; // vis[0]는 불, vis[1]은 지훈
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q1; // 불
    queue<pair<int, int>> q2; // 지훈
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                q1.push({i, j});
                vis[0][i][j] = 1;
            } else if (board[i][j] == 'J') {
                q2.push({i, j});
                vis[1][i][j] = 1;
            }
        }
    }
    while (!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '#' || vis[0][nx][ny] != 0)
                continue;
            q1.push({nx, ny});
            vis[0][nx][ny] = vis[0][cur.X][cur.Y] + 1;
        }
    }
    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << vis[1][cur.X][cur.Y];
                return 0;
            }
            if (vis[1][nx][ny] != 0 || board[nx][ny] == '#' ||
                (vis[0][nx][ny] > 0 && vis[0][nx][ny] <= vis[1][cur.X][cur.Y] + 1))
                continue;
            q2.push({nx, ny});
            vis[1][nx][ny] = vis[1][cur.X][cur.Y] + 1;
        }
    }
    cout << "IMPOSSIBLE";
}
