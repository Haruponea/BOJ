#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y, k;
int board[22][22];
int dice1[6];//0up, 1n, 2e, 3w, 4s, 5d
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int roll[4][4] = {
    {3,5,2,0}, //1
    {5,3,0,2}, //2
    {0,4,5,1}, //3
    {0,1,5,4}  //4
};
void move(int dir) {
    int dice2[6];
    for (int i = 0; i < 6; i++) {
        dice2[i] = dice1[i];
    }
    for (int i = 0; i < 4; i++) {
        dice2[roll[dir][i]] = dice1[roll[dir][(i + 1) % 4]];
    }
    for (int i = 0; i < 6; i++)
        dice1[i] = dice2[i];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    if (board[x][y] == 0) board[x][y] = dice1[5];
    else {
        dice1[5] = board[x][y];
        board[x][y] = 0;
    }
    while (k--) {
        int dir;
        cin >> dir;
        dir--;
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx == n || ny >= m) continue;
        x = nx, y = ny;
        move(dir);
        if (board[nx][ny] == 0) {
            board[nx][ny] = dice1[5];
        }
        else {
            dice1[5] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << dice1[0]<<'\n';
    }
}
