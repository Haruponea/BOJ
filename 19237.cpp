#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct sharkinfo {
    int x;
    int y;
    int dir;
    vector<int> priority[5];
};

struct boardinfo {
    int smell;
    int smell_time;
    int curshark;
};

boardinfo board[22][22];
sharkinfo shark[402];

int n, m, k, sharkcnt;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    sharkcnt = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 0) continue;
            else {
                board[i][j].curshark = a;
                shark[a].x = i; shark[a].y = j;
                board[i][j].smell = a;
                board[i][j].smell_time = k;
            }
        }
    }
    for (int i = 1; i <= m; i++) cin >> shark[i].dir;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int q = 0; q < 4; q++) {
                int a;
                cin >> a;
                shark[i].priority[j].push_back(a);
            }
        }
    }
    int t = 0;
    while (sharkcnt != 1 && t <= 1000) {
        t++;
        for (int i = 1; i <= m; i++) {
            if (shark[i].x == -1) continue;
            board[shark[i].x][shark[i].y].curshark = 0;
        }
        for (int i = m; i >= 1; i--) {
            if (shark[i].x == -1) continue;
            bool moved = false;
            for (int d : shark[i].priority[shark[i].dir]) {
                int nx = shark[i].x + dx[d];
                int ny = shark[i].y + dy[d];
                if (nx<1 || nx>n || ny<1 || ny>n) continue;
                if (board[nx][ny].smell != 0) continue;
                moved = true;
                if (board[nx][ny].curshark != 0) {
                    int dieshark = board[nx][ny].curshark;
                    shark[dieshark].x = -1;
                    sharkcnt--;
                }
                board[nx][ny].curshark = i;
                shark[i].dir = d; shark[i].x = nx; shark[i].y = ny;
                break;
            }
            if (!moved) {
                for (int d : shark[i].priority[shark[i].dir]) {
                    int nx = shark[i].x + dx[d];
                    int ny = shark[i].y + dy[d];
                    if (nx<1 || nx>n || ny<1 || ny>n) continue;
                    if (board[nx][ny].smell != i) continue;
                    board[nx][ny].curshark = i;
                    shark[i].dir = d; shark[i].x = nx; shark[i].y = ny;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j].smell == 0) continue;
                else {
                    board[i][j].smell_time--;
                    if (board[i][j].smell_time == 0)
                        board[i][j].smell = 0;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if (shark[i].x == -1) continue;
            board[shark[i].x][shark[i].y].smell = i;
            board[shark[i].x][shark[i].y].smell_time = k;
        }
    }
    if (t > 1000) cout << -1;
    else cout << t;
}
