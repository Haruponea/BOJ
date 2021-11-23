#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, sharkx, sharky, d, s;
int explode_cnt[4];
int board[52][52];
int tmp[52][52];
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

int ddx[4] = { 0,1,0,-1 };
int ddy[4] = { -1,0,1,0 };
vector<pair<int, int>> next;
void blizzard() {
    int nx = sharkx + dx[d];
    int ny = sharky + dy[d];
    for (int i = 0; i < s; i++) {
        board[nx][ny] = 0;
        nx += dx[d];
        ny += dy[d];
    }
}
void move_ball() {
    int boardidx = 0, tmpidx = 0;
    for (int i = 0; i < 52; i++) fill(tmp[i], tmp[i] + 52, 0);
    while (true) {
        if(board[::next[boardidx].first][::next[boardidx].second] == 0) {
            boardidx++;
        }
        else {
            tmp[::next[tmpidx].first][::next[tmpidx].second] = board[::next[boardidx].first][::next[boardidx].second];
            tmpidx++;
            boardidx++;
        }
        if (boardidx == ::next.size() - 1) break;
    }
    swap(board, tmp);
}
bool explosion() {
    bool done = false;
    int cnt = 1, idx = 1, curnum = -1;
    while (curnum != 0) {
        if (board[::next[idx].first][::next[idx].second] == curnum) {
            cnt++;
            idx++;
        }
        else {
            if (cnt >= 4) {
                done = true;
                explode_cnt[board[::next[idx - 1].first][::next[idx - 1].second]] += cnt;
                for (int i = 0; i < cnt; i++) {
                    board[::next[idx - 1 - i].first][::next[idx - 1 - i].second] = 0;
                }
            }
            cnt = 1;
            curnum = board[::next[idx].first][::next[idx].second];
            idx++;
        }
    }
    return done;
}
void change_ball() {
    int cnt = 0, idx = 1, curnum = board[::next[1].first][::next[1].second];
    for (int i = 0; i < 52; i++) fill(tmp[i], tmp[i] + 52, 0);
    int tmpidx = 1;
    tmp[sharkx][sharky] = -1;
    while (curnum != 0) {
        if (board[::next[idx].first][::next[idx].second] == curnum) {
            cnt++;
            idx++;
        }
        else {
            tmp[::next[tmpidx].first][::next[tmpidx].second] = cnt;
            tmpidx++; if (::next[tmpidx].second == 0) break;
            tmp[::next[tmpidx].first][::next[tmpidx].second] = board[::next[idx-1].first][::next[idx-1].second];
            tmpidx++; if (::next[tmpidx].second == 0) break;
            cnt = 1;
            curnum = board[::next[idx].first][::next[idx].second];
            idx++;
        }
    }
    swap(board, tmp);
}
void solve() {
    blizzard();
    move_ball();
    while (true) {
        if (explosion()) {
            move_ball();
        }
        else break;
    }
    change_ball();
}
void init_next() {
    int curx = sharkx, cury = sharky;
    int speed = 1;
    ::next.push_back({ curx,cury });
    while (true) {
        for (int dir = 0; dir < 2; dir++) {
            if (cury == 0) {
                return;
            }
            for (int j = 0; j < speed; j++) {
                curx += ddx[dir];
                cury += ddy[dir];
                ::next.push_back({ curx,cury });
            }
        }
        speed++;
        for (int dir = 2; dir < 4; dir++) {
            for (int j = 0; j < speed; j++) {
                curx += ddx[dir];
                cury += ddy[dir];
                ::next.push_back({ curx,cury });
            }
        }
        speed++;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    sharkx = sharky = (n + 1) / 2;
    board[sharkx][sharky] = -1;
    init_next();
    while (m--) {
        cin >> d >> s;
        solve();
    }
    cout << (explode_cnt[1])+(2 * explode_cnt[2]) + (3 * explode_cnt[3]);
}
