#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int RGBBFS(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0) {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                char curColor = board[i][j];
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] != 0 || board[nx][ny] != curColor)
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return ans;
}

int RBBFS(int n) {
    for (int i = 0; i < 102; i++)
        fill(vis[i], vis[i] + 102, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0) {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                char curColor = board[i][j];
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] != 0 || (curColor == 'B' && board[nx][ny] != 'B') ||
                            (curColor != 'B' && board[nx][ny] == 'B'))
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return ans;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    int RGB, RB;
    RGB = RGBBFS(n);
    RB = RBBFS(n);
    cout << RGB << ' ' << RB;
}
