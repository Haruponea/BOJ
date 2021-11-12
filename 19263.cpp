#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

struct fishinfo {
    int dir;
    int x;
    int y;
    bool live;
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int ans, cnt;

void movefish(int tmp[][4], fishinfo fish[]) {
    for (int i = 1; i <= 16; i++) {
        if (fish[i].live == false) continue;
        bool moved = false;
        int curdir = fish[i].dir, curx=fish[i].x, cury=fish[i].y;
        for (int j = 0; j < 8; j++) {
            int nx = curx + dx[curdir];
            int ny = cury + dy[curdir];
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || tmp[nx][ny] == 0) {
                curdir = (curdir + 1) % 8;
                continue;
            }
            int nextfish = tmp[nx][ny];
            moved = true;
            if (nextfish == -1) {
                fish[i].x = nx; fish[i].y = ny; fish[i].dir = curdir;
                swap(tmp[nx][ny], tmp[curx][cury]);
            }
            else {
                fish[nextfish].x = curx; fish[nextfish].y = cury;
                fish[i].x = nx; fish[i].y = ny; fish[i].dir = curdir;
                swap(tmp[nx][ny], tmp[curx][cury]);
            }
            break;
        }
    }
}

void moveshark(int board[][4], int sharkx, int sharky, int sharkdir, fishinfo fish[]) {
    int tmp[4][4];
    fishinfo fishtmp[17];
    for (int i = 0; i < 17; i++) fishtmp[i] = fish[i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = board[i][j];
    movefish(tmp, fishtmp);
    int nx = sharkx + dx[sharkdir], ny = sharky + dy[sharkdir];
    bool possible = false;
    while (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
        if (tmp[nx][ny] > 0) {
            int nextsharkdir = fishtmp[tmp[nx][ny]].dir;
            int fishnum = tmp[nx][ny];
            cnt += fishnum;
            fishtmp[fishnum].live = false;
            tmp[sharkx][sharky] = -1;
            tmp[nx][ny] = 0;
            moveshark(tmp, nx, ny, nextsharkdir,fishtmp);
            cnt -= fishnum;
            tmp[sharkx][sharky] = 0;
            tmp[nx][ny] = fishnum;
            fishtmp[fishnum].live = true;
            possible = true;
        }
        nx += dx[sharkdir], ny += dy[sharkdir];
    }
    if (!possible) {
        ans = max(ans, cnt);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int board[4][4];
    fishinfo fish[17];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            fish[a].dir = b - 1;
            fish[a].x = i; fish[a].y = j; fish[a].live = true;
            board[i][j] = a;
        }
    }
    int sharkdir = fish[board[0][0]].dir;
    cnt += board[0][0];
    fish[board[0][0]].live = false;
    board[0][0] = 0;
    moveshark(board,0,0,sharkdir, fish);
    cout << ans;
}
