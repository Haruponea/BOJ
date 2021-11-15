#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, q, maxlen;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int board[66][66];
int tmp[66][66];
bool vis[66][66];
vector<int> level;

void rotate(int sx, int sy, int level) {
    int lvl = (1 << level);
    for (int x = sx; x < maxlen; x += lvl) {
        for (int y = sy; y < maxlen; y += lvl) {
            for (int i = 0; i < lvl; i++) {
                for (int j = 0; j < lvl; j++) {
                    tmp[x+i][y+j] = board[x+lvl-1-j][y+i];
                }
            }
        }
    }
    for (int i = 0; i < maxlen; i++) {
        for (int j = 0; j < maxlen; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

bool check(int x, int y) {
    int cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir]; int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= maxlen || ny >= maxlen)continue;
        if (tmp[nx][ny] > 0) cnt++;
    }
    if (cnt < 3) return false;
    else return true;
}

void remove_ice() {
    for (int i = 0; i < maxlen; i++) {
        for (int j = 0; j < maxlen; j++) {
            if (tmp[i][j] == 0) continue;
            if (!check(i, j)) {
                board[i][j] -= 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    maxlen = (1 << n);
    for (int i = 0; i < maxlen; i++) {
        for (int j = 0; j < maxlen; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int l;
        cin >> l;
        level.push_back(l);
    }
    for (int lvl : level) {
        rotate(0, 0, lvl);
        remove_ice();
    }
    int icesum = 0;
    int maxsize = 0;
    for (int i = 0; i < maxlen; i++) {
        for (int j = 0; j < maxlen; j++) {
            if (board[i][j] > 0) icesum+=board[i][j];
            if (vis[i][j] == true || board[i][j]==0) continue;
            queue<pair<int, int>>q;
            q.push({ i,j });
            vis[i][j] = true;
            int cnt = 0;
            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                cnt++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= maxlen || ny >= maxlen) continue;
                    if (board[nx][ny] == 0 || vis[nx][ny] == true) continue;
                    q.push({ nx,ny });
                    vis[nx][ny] = true;
                }
            }
            maxsize = max(maxsize, cnt);
        }
    }
    cout << icesum << '\n' << maxsize;
}
