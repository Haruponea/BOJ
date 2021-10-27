#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int board[4][5][5][5];
int ans = 300;
int map[5][5][5];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void bfs(int z, int x, int y) {
    tuple<int, int, int> target = { 4,4,4 };
    int vis[7][7][7] = {};
    queue<tuple<int, int, int>> q;
    q.push({ z,x,y });
    vis[z][x][y] = 1;
    while (!q.empty()) {
        tuple<int, int, int> cur = q.front(); q.pop();
        if (cur == target) {
            ans = min(ans, vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] - 1);
        }
        for (int i = 0; i < 6; i++) {
            int nz = get<0>(cur) + dz[i];
            int nx = get<1>(cur) + dx[i];
            int ny = get<2>(cur) + dy[i];
            if (nz < 0 || nx < 0 || ny < 0 || nz >= 5 || nx >= 5 || ny >= 5) continue;
            if (vis[nz][nx][ny] != 0 || map[nz][nx][ny] == 0)continue;
            q.push({nz, nx, ny});
            vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[0][i][j][k];
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][5 - 1 - k][j];
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][5 - 1 - k][j];
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][5 - 1 - k][j];
    }
    int order[5] = { 0,1,2,3,4 };
    do {
        for (int tmp = 0; tmp < 1024; tmp++) {
            int brute = tmp;
            for (int i = 0; i < 5; i++) {
                int dir = brute % 4;
                brute /= 4;
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        map[i][j][k] = board[dir][order[i]][j][k];
                    }
                }
            }
            if (map[0][0][0] == 0 || map[4][4][4] == 0) continue;
            bfs(0, 0, 0);
        }
    } while (next_permutation(order, order + 5));
    if (ans == 300) ans = -1;
    cout << ans;
}
