#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int board[102][102];
int n, x, y, d, g, cnt;

void dragon(int sx,int sy, int dir, int generation, deque<pair<int,int>>& dq) {
    if (generation == 0) {
        board[sx + dx[dir]][sy + dy[dir]] = 1;
        dq.push_front({ sx + dx[dir],sy + dy[dir] });
        sx += dx[dir]; sy += dy[dir];
    }
    else {
        deque<pair<int, int>> nextdq;
        for (int i = 1; i < dq.size();i++) {
            int nx = sy + sx - dq[i].second;
            int ny = sy - sx + dq[i].first;
            nextdq.push_front({ nx,ny });
            board[nx][ny] = 1;
        }
        for (pair<int, int>p : dq) 
            nextdq.push_back(p);
        swap(dq,nextdq);
        sx = dq.front().first; sy = dq.front().second;
    }
    if (g == generation) { 
        return;
    }
    dragon(sx, sy, (dir + 1) % 4, generation + 1, dq);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    while (n--) {
        deque<pair<int, int>> dq;
        cin >> x >> y >> d >> g;
        dq.push_back({ x,y });
        board[x][y] = 1;
        dragon(x, y, d, 0, dq);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1){
                cnt++;
            }
        }
    }
    cout << cnt;
}
