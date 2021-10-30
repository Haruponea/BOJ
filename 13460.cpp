#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n, m, ans, rx, ry, bx, by;
char board[12][12];
int vis[12][12][12][12];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<tuple<int, int, int, int>> q; //rx,ry,bx,by
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'R') {
                board[i][j] = '.';
                rx = i; ry = j;
            }
            else if (board[i][j] == 'B') {
                bx = i; by = j;
                board[i][j] = '.';
            }
        }
    }
    q.push({ rx,ry,bx,by });
    vis[rx][ry][bx][by] = 1;
    while (!q.empty()) {
        int crx, cry, cbx, cby;
        tie(crx, cry, cbx, cby) = q.front(); q.pop();
        if (board[crx][cry] == 'O') {
            cout << vis[crx][cry][cbx][cby]-1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nrx = crx, nry = cry, nbx = cbx, nby = cby;
            while (true) {
                if (board[nrx][nry] == '.') {
                    nrx += dx[i]; nry += dy[i];
                }
                else {
                    if (board[nrx][nry] == '#') {
                        nrx -= dx[i]; nry -= dy[i];
                    }
                    break;
                }
            }
            while (true) {
                if (board[nbx][nby] == '.') {
                    nbx += dx[i]; nby += dy[i];
                }
                else {
                    if (board[nbx][nby] == '#') {
                        nbx -= dx[i]; nby -= dy[i];
                    }
                    break;
                }
            }
            if (nrx == nbx && nry == nby) {
                if (board[nrx][nry] != 'O') {
                    int rd = abs(nrx - crx) + abs(nry - cry);
                    int bd = abs(nbx - cbx) + abs(nby - cby);
                    if (rd < bd) {
                        nbx -= dx[i]; nby -= dy[i];
                    }
                    else {
                        nrx -= dx[i]; nry -= dy[i];
                    }
                }
                else
                    continue;
            }
            if (vis[nrx][nry][nbx][nby] == 0) {
                if (vis[crx][cry][cbx][cby] > 10) continue;

                vis[nrx][nry][nbx][nby] = vis[crx][cry][cbx][cby] + 1;
                q.push({ nrx,nry,nbx,nby });
            }
        }
    }
    cout << -1;
}
