#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string board[13];
bool vis[14][8];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 12, m = 6, combo = 0;
    bool puyo = false;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    do{
        puyo = false;
        for (int k = 0; k < 13; k++) fill(vis[k], vis[k] + 7, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;
                vector<pair<int, int>> v;
                char curcolor = board[i][j];
                queue<pair<int, int>> q;
                q.push({ i,j });
                vis[i][j] = true;
                int cnt = 0;
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop(); cnt++;
                    v.push_back(cur);
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (board[nx][ny] != curcolor || vis[nx][ny] == true) continue;
                        vis[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                }
                if (cnt >= 4) {
                    puyo = true;
                    for (auto cur : v) {
                        board[cur.first][cur.second] = '.';
                    }
                }
            }
        }
        if (puyo) {
            combo++;
            for (int i = n-2; i >=0; i--) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == '.')continue;
                    int curx = i, cury = j;
                    int nx = i + 1, ny = j;
                    while (nx < n && board[nx][ny] == '.') {
                        board[nx][ny] = board[curx][cury];
                        board[curx][cury] = '.';
                        curx = nx;
                        nx += 1;
                    }
                }
            }
        }
    } while (puyo);
    cout << combo;
}
