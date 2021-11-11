#include <iostream>
#include <algorithm>
using namespace std;
struct chess {
    int x;
    int y;
    int dir;
};
int n, k;
int board[14][14];
vector<int> board_v[14][14];
int dx[5] = { -2,0,0,-1,1 };
int dy[5] = { -2,1,-1,0,0 };
chess mal[12];

void change_dir(int idx) {
    int idx_dir = mal[idx].dir;
    if (idx_dir == 1) mal[idx].dir = 2;
    else if (idx_dir == 2) mal[idx].dir = 1;
    else if (idx_dir == 3) mal[idx].dir = 4;
    else if (idx_dir == 4) mal[idx].dir = 3;
}
void movered(int& curx, int& cury, int nx, int ny, int curlen, int curidx) {
    for (int i = curlen - 1; i >= curidx; i--) {
        board_v[nx][ny].push_back(board_v[curx][cury][i]);
        mal[board_v[curx][cury][i]].x = nx; mal[board_v[curx][cury][i]].y = ny;
    }
    for (int i = curidx; i < curlen; i++)
        board_v[curx][cury].pop_back();
    curx = nx;
    cury = ny;
}

void movewhite(int& curx, int& cury, int nx, int ny, int curlen, int curidx) {
    for (int i = curidx; i < curlen; i++) {
        board_v[nx][ny].push_back(board_v[curx][cury][i]);
        mal[board_v[curx][cury][i]].x = nx, mal[board_v[curx][cury][i]].y = ny;
    }
    for (int i = curidx; i < curlen; i++)
        board_v[curx][cury].pop_back();
    curx = nx;
    cury = ny;
}

bool check(int curx, int cury) {
    if (board_v[curx][cury].size() >= 4) return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> mal[i].x >> mal[i].y >> mal[i].dir;
        board_v[mal[i].x][mal[i].y].push_back(i);
    }
    int turn = 1;
    bool possible = false;
    while (turn <= 1000 && !possible) {
        for (int idx = 0; idx < k && !possible; idx++) {
            int curx = mal[idx].x, cury = mal[idx].y, curdir = mal[idx].dir;
            int nx = curx + dx[curdir], ny = cury + dy[curdir];
            int curidx = 0;
            int curlen = board_v[curx][cury].size();
            while (board_v[curx][cury][curidx] != idx) {
                curidx++;
            }
            if (nx <1 || ny <1 || nx>n || ny>n || board[nx][ny]==2) {
                change_dir(idx);
                curdir = mal[idx].dir;
                nx = curx + dx[curdir]; ny = cury + dy[curdir];
                if (!(nx <1 || ny <1 || nx>n || ny>n || board[nx][ny] == 2)) {
                    if (board[nx][ny] == 1) movered(curx, cury, nx, ny, curlen, curidx);
                    else if (board[nx][ny] == 0)movewhite(curx, cury, nx, ny, curlen, curidx);
                }
            }
            else if (board[nx][ny] == 1) {
                movered(curx, cury, nx, ny, curlen, curidx);
            }
            else {
                movewhite(curx, cury, nx, ny, curlen, curidx);
            }
            possible=check(curx, cury);
        }
        if(!possible) turn++;
    }
    if (turn <= 1000) cout << turn;
    else cout << -1;
}
