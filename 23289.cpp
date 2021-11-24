#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int r, c, k, w;
vector<pair<int, int>> searchpoint;
vector<tuple<int, int, int>> heater;//
int board[23][23];
int tmp[23][23];
bool wall[23][23][23][23];
int dx[5] = { 0,0,0,-1,1 };//오왼위아
int dy[5] = { 0,1,-1,0,0 };
void wind_out() {
    for (int idx = 0; idx < heater.size(); idx++) {
        for (int i = 0; i < 23; i++) fill(tmp[i], tmp[i] + 23, 0);
        int x, y, dir;
        tie(x, y, dir) = heater[idx];
        queue<tuple<int, int, int>> q;
        q.push({ x + dx[dir],y + dy[dir], 5 });
        tmp[x + dx[dir]][y + dy[dir]] = 5;
        while (!q.empty()) {
            int curx, cury, curtemp;
            tie(curx,cury,curtemp) = q.front(); q.pop();
            if (curtemp == 1) continue;
            if (dir == 1) {
                if (curx - 1 >= 1 && cury + 1 <= c && wall[curx][cury][curx - 1][cury] == false && wall[curx - 1][cury][curx - 1][cury + 1] == false && tmp[curx-1][cury+1]==0) {
                    tmp[curx - 1][cury + 1] = curtemp - 1;
                    q.push({ curx - 1,cury + 1,curtemp - 1 });
                }
                if (cury + 1 <= c && tmp[curx][cury + 1] == 0 && wall[curx][cury][curx][cury + 1] == false) {
                    tmp[curx][cury + 1] = curtemp - 1;
                    q.push({ curx,cury + 1,curtemp - 1 });
                }
                if (curx + 1 <=r && cury + 1 <= c && wall[curx][cury][curx + 1][cury] == false && wall[curx + 1][cury][curx + 1][cury + 1] == false && tmp[curx + 1][cury + 1] == 0) {
                    tmp[curx + 1][cury + 1] = curtemp - 1;
                    q.push({ curx + 1,cury + 1,curtemp - 1 });
                }
            }
            else if (dir == 2) {
                if (curx - 1 >= 1 && cury - 1 >= 1 && wall[curx][cury][curx - 1][cury] == false && wall[curx - 1][cury][curx - 1][cury - 1] == false && tmp[curx - 1][cury - 1] == 0) {
                    tmp[curx - 1][cury - 1] = curtemp - 1;
                    q.push({ curx - 1,cury - 1,curtemp - 1 });
                }
                if (cury - 1 >= 1 && tmp[curx][cury - 1] == 0 && wall[curx][cury][curx][cury - 1] == false) {
                    tmp[curx][cury - 1] = curtemp - 1;
                    q.push({ curx,cury - 1,curtemp - 1 });
                }
                if (curx + 1 <= r && cury - 1 >= 1 && wall[curx][cury][curx + 1][cury] == false && wall[curx + 1][cury][curx + 1][cury - 1] == false && tmp[curx + 1][cury - 1] == 0) {
                    tmp[curx + 1][cury - 1] = curtemp - 1;
                    q.push({ curx + 1,cury - 1,curtemp - 1 });
                }
            }
            else if (dir == 3) {
                if (curx - 1 >= 1 && cury - 1 >= 1 && wall[curx][cury][curx][cury - 1] == false && wall[curx][cury - 1][curx - 1][cury - 1] == false && tmp[curx - 1][cury - 1] == 0) {
                    tmp[curx - 1][cury - 1] = curtemp - 1;
                    q.push({ curx - 1,cury - 1,curtemp - 1 });
                }
                if (curx - 1 >= 1 && tmp[curx - 1][cury] == 0 && wall[curx][cury][curx - 1][cury] == false) {
                    tmp[curx - 1][cury] = curtemp - 1;
                    q.push({ curx - 1,cury,curtemp - 1 });
                }
                if (curx - 1 >= 1 && cury + 1 <= c && wall[curx][cury][curx][cury + 1] == false && wall[curx][cury + 1][curx - 1][cury + 1] == false && tmp[curx - 1][cury + 1] == 0) {
                    tmp[curx - 1][cury + 1] = curtemp - 1;
                    q.push({ curx - 1,cury + 1,curtemp - 1 });
                }
            }
            else {
                if (curx + 1 <= r && cury - 1 >= 1 && wall[curx][cury][curx][cury-1] == false && wall[curx][cury-1][curx + 1][cury - 1] == false && tmp[curx + 1][cury - 1] == 0) {
                    tmp[curx + 1][cury - 1] = curtemp - 1;
                    q.push({ curx + 1,cury - 1,curtemp - 1 });
                }
                if (curx + 1 <= r && tmp[curx + 1][cury] == 0 && wall[curx][cury][curx+1][cury] == false) {
                    tmp[curx + 1][cury] = curtemp - 1;
                    q.push({ curx + 1,cury,curtemp - 1 });
                }
                if (curx + 1 <= r && cury + 1 <= c && wall[curx][cury][curx][cury+1] == false && wall[curx][cury+1][curx + 1][cury + 1] == false && tmp[curx + 1][cury + 1] == 0) {
                    tmp[curx + 1][cury + 1] = curtemp - 1;
                    q.push({ curx + 1,cury + 1,curtemp - 1 });
                }
            }
        }
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) board[i][j] += tmp[i][j];
    }
}

void temperature_spread() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (board[i][j] == 0) continue;
            for (int m = 1; m < 5; m++) {
                int nx = i + dx[m];
                int ny = j + dy[m];
                if (nx<1 || ny<1 || nx>r || ny>c) continue;
                if (wall[i][j][nx][ny] == true) continue;
                if (board[i][j] <= board[nx][ny]) continue;
                int d = (board[i][j] - board[nx][ny]) / 4;
                tmp[i][j] -= d;
                tmp[nx][ny] += d;
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

void temperature_decrease() {
    for (int i = 1; i <= r; i++) {
        if (board[i][1] > 0) board[i][1]--;
        if (board[i][c] > 0) board[i][c]--;
    }
    for (int j = 2; j < c; j++) {
        if (board[1][j] > 0) board[1][j]--;
        if (board[r][j] > 0) board[r][j]--;
    }
}

bool check_searchpoint() {
    bool possible = true;
    for (pair<int, int> cur : searchpoint) {
        if (board[cur.first][cur.second] < k) {
            possible = false;
            break;
        }
    }
    return possible;
}

void solve() {
    int choco = 0;
    while (choco <= 100) {
        wind_out();
        temperature_spread();
        temperature_decrease();
        choco++;
        if (check_searchpoint())
            break;
    }
    cout << choco;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int a;
            cin >> a;
            if (a == 0) continue;
            else if (a == 5) {
                searchpoint.push_back({ i,j });
            }
            else {
                heater.push_back({ i,j,a });
            }
        }
    }
    cin >> w;
    for (int i = 0; i < w; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == 0) {
            wall[x][y][x - 1][y] = true;
            wall[x - 1][y][x][y] = true;
        }
        else {
            wall[x][y][x][y + 1] = true;
            wall[x][y + 1][x][y] = true;
        }
    }
    solve();
}
