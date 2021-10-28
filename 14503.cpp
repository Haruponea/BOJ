#include <iostream>
#include <algorithm>
#include <stack>
#include <tuple>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int board[52][52];
int vis[52][52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cnt = 0, r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    d = (4 - d) % 4;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    stack<tuple<int, int, int>> s;
    s.push({ r,c,d });
    vis[r][c] = 1;
    cnt++;
    while (!s.empty()) {
        bool clean = false;
        int cx, cy, cd;
        tie(cx, cy, cd) = s.top(); s.pop();
        for (int i = 1; i <= 4; i++) {
            int nx = cx + dx[(cd + i) % 4];
            int ny = cy + dy[(cd + i) % 4];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 1 || vis[nx][ny] != 0) continue;
            clean = true;
            s.push({ nx,ny,(cd + i) % 4 });
            vis[nx][ny] = vis[cx][cy]+1;
            cnt++;
            break;
        }
        if (clean == false) {
            int backdir = (2 + cd) % 4;
            if (board[cx + dx[backdir]][cy + dy[backdir]] == 0) {
                s.push({ cx + dx[backdir],cy + dy[backdir],cd });
            }
            else{
                break;
            }
        }
    }
    
    cout << cnt;
    
}
