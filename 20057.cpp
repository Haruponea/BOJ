#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int board[502][502];
bool vis[502][502];
int outsand = 0;

bool OOR(int x, int y) {
    if (x<1 || y<1 || x>n || y>n) return true;
    else return false;
}
void movesand(int curx, int cury, int dir) {
    int asand;
    if (dir % 2 == 0) {
        int nx = curx + dx[dir], ny = cury + dy[dir];
        int ysand = board[nx][ny];
        board[nx][ny] = 0;
        int ysand1=(ysand*1)/100, ysand7= (ysand * 7) / 100, ysand10= (ysand * 10) / 100, ysand2= (ysand * 2) / 100, ysand5= (ysand * 5) / 100;
        int tx, ty, sx, sy;
        for (int i = 0; i < 4; i++) {
            if (i == 3) {
                sx = curx + i * dx[dir], sy = cury + i * dy[dir];
                if (OOR(sx, sy)) outsand += ysand5;
                else board[sx][sy] += ysand5;
                ysand -= ysand5;
                continue;
            }
            sx = curx + i * dx[dir], sy = cury + i * dy[dir];
            for (int j = 0; j < 2; j++) {
                int ndir;
                if (j == 0) ndir = 1;
                else ndir = 3;
                tx = sx + dx[ndir], ty = sy + dy[ndir];
                if (i == 0) {
                    if (OOR(tx, ty))outsand += ysand1;
                    else board[tx][ty] += ysand1;
                    ysand -= ysand1;
                }
                else if (i == 1) {
                    if (OOR(tx, ty))outsand += ysand7;
                    else board[tx][ty] += ysand7;
                    ysand -= ysand7;
                    
                    if (OOR(tx+dx[ndir], ty+dy[ndir]))outsand += ysand2;
                    else board[tx+dx[ndir]][ty+dy[ndir]] += ysand2;
                    ysand -= ysand2;
                }
                else if (i == 2) {
                    if (OOR(tx, ty))outsand += ysand10;
                    else board[tx][ty] += ysand10;
                    ysand -= ysand10;
                }
            }
        }
        asand = ysand;
    }
    else {
        int nx = curx + dx[dir], ny = cury + dy[dir];
        int ysand = board[nx][ny];
        board[nx][ny] = 0;
        int ysand1 = (ysand * 1) / 100, ysand7 = (ysand * 7) / 100, ysand10 = (ysand * 10) / 100, ysand2 = (ysand * 2) / 100, ysand5 = (ysand * 5) / 100;
        int tx, ty, sx, sy;
        for (int i = 0; i < 4; i++) {
            if (i == 3) {
                sx = curx + i * dx[dir], sy = cury + i * dy[dir];
                if (OOR(sx, sy)) outsand += ysand5;
                else board[sx][sy] += ysand5;
                ysand -= ysand5;
                continue;
            }
            sx = curx + i * dx[dir], sy = cury + i * dy[dir];
            for (int j = 0; j < 2; j++) {
                int ndir;
                if (j == 0) ndir = 0;
                else ndir = 2;
                tx = sx + dx[ndir], ty = sy + dy[ndir];
                if (i == 0) {
                    if (OOR(tx, ty))outsand += ysand1;
                    else board[tx][ty] += ysand1;
                    ysand -= ysand1;
                }
                else if (i == 1) {
                    if (OOR(tx, ty))outsand += ysand7;
                    else board[tx][ty] += ysand7;
                    ysand -= ysand7;

                    if (OOR(tx + dx[ndir], ty + dy[ndir]))outsand += ysand2;
                    else board[tx + dx[ndir]][ty + dy[ndir]] += ysand2;
                    ysand -= ysand2;
                }
                else if (i == 2) {
                    if (OOR(tx, ty))outsand += ysand10;
                    else board[tx][ty] += ysand10;
                    ysand -= ysand10;
                }
            }
        }
        asand = ysand;
    }
    int ax = curx + 2 * dx[dir], ay = cury + 2 * dy[dir];
    if (OOR(ax, ay)) outsand += asand;
    else board[ax][ay] += asand;
}

int changedir(int dir) {
    return (dir + 1) % 4;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> board[i][j];
    int windx = (n / 2) + 1, windy = (n / 2) + 1;
    int dir = 0; int cnt = 0;
    vis[windx][windy] = true;
    while (windx>0 && windy>0) {
        movesand(windx, windy, dir);
        windx += dx[dir]; windy += dy[dir];
        vis[windx][windy] = true;
        if (vis[windx+dx[changedir(dir)]][windy+dy[changedir(dir)]]==false) {
            dir = changedir(dir);
        }
    }
    cout << outsand;
}
