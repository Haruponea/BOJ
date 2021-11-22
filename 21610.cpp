#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };

int n, m;
int board[53][53];
bool cloud[53][53];
int board_tmp[53][53];
bool cloud_tmp[53][53];

void move(int d, int s){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cloud[i][j] == true) {
                int nx = (i + dx[d] * s) % n;
                int ny = (j + dy[d] * s) % n;
                if (nx < 0) nx = n + nx;
                else if (nx == 0) nx = n;
                
                if (ny < 0) ny = n + ny;
                else if (ny == 0) ny = n;
                cloud[i][j] = false;
                cloud_tmp[nx][ny] = true;
                board[nx][ny] += 1;
            }
        }
    }
}
void water_copy_bug() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cloud_tmp[i][j] == true) {
                for (int dir : {2, 4, 6, 8}) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx<1 || ny<1 || nx>n || ny>n)continue;
                    if (board[nx][ny] > 0) board[i][j]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cloud_tmp[i][j] == true) {
                cloud_tmp[i][j] = false;
            }
            else if (board[i][j] >= 2) {
                cloud[i][j] = true;
                board[i][j] -= 2;
            }
        }
    }
}
void solve(int d, int s) {
    move(d, s);
    water_copy_bug();
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
    cloud[n][1] = cloud[n][2] = cloud[n - 1][1] = cloud[n - 1][2] = true;
    while (m--) {
        int d, s;
        cin >> d >> s;
        solve(d, s);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += board[i][j];
        }
    }
    cout << ans;
}
