#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, ans = 1;
    bool is_every = true;
    cin >> m >> n;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] != 0)
                continue;
            q.push({nx, ny});
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            ans = max(ans, board[nx][ny]);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
                is_every = false;
    cout << (is_every ? ans - 1 : -1);
}
