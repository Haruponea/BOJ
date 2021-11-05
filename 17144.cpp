#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx1[4] = { -1,0,1,0 };
int dy1[4] = { 0,1,0,-1 };
int dx2[4] = { 1,0,-1,0 };
int dy2[4] = { 0,1,0,-1 };
int r, c, t, T, ans;
int board[52][52];
int add[52][52];
int cleaner[2][2]; //clear[0] is top, clear[1] is bottom

void spread() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] > 0) {
                int spread_amount = board[i][j] / 5;
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx1[dir];
                    int ny = j + dy1[dir];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if (board[nx][ny] == -1) continue;
                    cnt++;
                    add[nx][ny] += spread_amount;
                }
                board[i][j] -= (spread_amount)*cnt;
            }
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void move() {
    int curx = cleaner[0][0], cury = cleaner[0][1];
    for (int dir = 0; dir < 4; dir++) {
        int nx = curx + dx1[dir];
        int ny = cury + dy1[dir];
        while (nx <= cleaner[0][0] && nx>=0 && ny<c && ny >=0) {
            if (board[nx][ny] == -1) {
                board[curx][cury] = 0;
                break;
            }
            else if (board[curx][cury] != -1) {
                board[curx][cury] = board[nx][ny];
            }
            curx = nx; cury = ny;
            nx += dx1[dir]; ny += dy1[dir];
        }
    }

    curx = cleaner[1][0], cury = cleaner[1][1];
    for (int dir = 0; dir < 4; dir++) {
        int nx = curx + dx2[dir];
        int ny = cury + dy2[dir];
        while (nx >= cleaner[1][0] && nx < r && ny < c && ny >= 0) {
            if (board[nx][ny] == -1) {
                board[curx][cury] = 0;
                break;
            }
            else if (board[curx][cury] != -1) {
                board[curx][cury] = board[nx][ny];
            }
            curx = nx; cury = ny;
            nx += dx2[dir]; ny += dy2[dir];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> T;
    int idx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                cleaner[idx][0] = i;
                cleaner[idx++][1] = j;
            }
        }
    }
    while (t<T) {
        spread();
        move();
        t++;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] > 0)
                ans += board[i][j];
        }
    }
    cout << ans;
}
