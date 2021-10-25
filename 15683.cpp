#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[10][10];
int check[10][10];
int dx[4] = { 0,0,1,-1 }; //우좌하상
int dy[4] = { 1,-1,0,0 };
int n, m, cctvlen, ans=100;
vector<pair<int, int>> cctv;

void func(int level) {
    if (level == cctvlen) {
        //cout << "------------------\n";
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << check[i][j] << ' ';
                if (board[i][j] != 6 && check[i][j] == 0) cnt++;
            }
            //cout << '\n';
        }
        ans = min(cnt, ans);
        //cout << '\n'; cout << '\n';
        return;
    }
    int cctvx = cctv[level].first;
    int cctvy = cctv[level].second;
    check[cctvx][cctvy] += 1;
    if (board[cctvx][cctvy] == 1) {
        for (int i = 0; i < 4; i++) {
            int nx = cctvx + dx[i];
            int ny = cctvy + dy[i];
            while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (board[nx][ny] == 6) {
                    break;
                }
                else {
                    check[nx][ny] += 1;
                }
                nx += dx[i]; ny += dy[i];
            }
            func(level + 1);
            nx -= dx[i]; ny -= dy[i];
            while (nx != cctvx || ny != cctvy) {
                check[nx][ny] -= 1;
                nx -= dx[i]; ny -= dy[i];
            }
        }
    }
    else if(board[cctvx][cctvy]==2){
        for (int st = 0; st <= 2; st += 2) {
            int nx1 = cctvx + dx[st];
            int ny1 = cctvy + dy[st];
            int nx2 = cctvx + dx[st + 1];
            int ny2 = cctvy + dy[st + 1];
            
            while (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m) {
                if (board[nx1][ny1] == 6) {
                    break;
                }
                else {
                    check[nx1][ny1] += 1;
                }
                nx1 += dx[st]; ny1 += dy[st];
            }
            while (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m) {
                if (board[nx2][ny2] == 6) {
                    break;
                }
                else {
                    check[nx2][ny2] += 1;
                }
                nx2 += dx[st + 1]; ny2 += dy[st + 1];
            }
            func(level + 1);
            nx1 -= dx[st]; ny1 -= dy[st]; nx2 -= dx[st + 1]; ny2 -= dy[st + 1];
            while (nx1 != cctvx || ny1 != cctvy) {
                check[nx1][ny1] -= 1;
                nx1 -= dx[st]; ny1 -= dy[st];
            }
            while (nx2 != cctvx || ny2 != cctvy) {
                check[nx2][ny2] -= 1;
                nx2 -= dx[st+1];  ny2 -= dy[st+1];
            }
        }
    }
    else if(board[cctvx][cctvy]==3){
        for (int i = 0; i < 4; i++) {
            int dir1 = i / 2; int dir2 = (2 + (i % 2));
            int nx1 = cctvx + dx[dir1];
            int ny1 = cctvy + dy[dir1];
            int nx2 = cctvx + dx[dir2];
            int ny2 = cctvy + dy[dir2];

            while (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m) {
                if (board[nx1][ny1] == 6) {
                    break;
                }
                else {
                    check[nx1][ny1] += 1;
                }
                nx1 += dx[dir1]; ny1 += dy[dir1];
            }
            while (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m) {
                if (board[nx2][ny2] == 6) {
                    break;
                }
                else {
                    check[nx2][ny2] += 1;
                }
                nx2 += dx[dir2]; ny2 += dy[dir2];
            }
            func(level + 1);
            nx1 -= dx[dir1]; ny1 -= dy[dir1]; nx2 -= dx[dir2]; ny2 -= dy[dir2];
            while (nx1 != cctvx || ny1 != cctvy) {
                check[nx1][ny1] -= 1;
                nx1 -= dx[dir1]; ny1 -= dy[dir1];
            }
            while (nx2 != cctvx || ny2 != cctvy) {
                check[nx2][ny2] -= 1;
                nx2 -= dx[dir2];  ny2 -= dy[dir2];
            }
        }
    }
    else if (board[cctvx][cctvy] == 4) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j != i) {
                    int nx = cctvx + dx[j];
                    int ny = cctvy + dy[j];
                    while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if (board[nx][ny] == 6) {
                            break;
                        }
                        else {
                            check[nx][ny] += 1;
                        }
                        nx += dx[j]; ny += dy[j];
                    }
                }
            }
            func(level + 1);
            for (int j = 0; j < 4; j++) {
                if (j != i) {
                    int nx = cctvx + dx[j];
                    int ny = cctvy + dy[j];
                    while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if (board[nx][ny] == 6) {
                            break;
                        }
                        else {
                            check[nx][ny] -= 1;
                        }
                        nx += dx[j]; ny += dy[j];
                    }
                }
            }
        }
    }
    else if (board[cctvx][cctvy] == 5) {
        for (int i = 0; i < 4; i++) {
            int nx = cctvx + dx[i];
            int ny = cctvy + dy[i];
            while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (board[nx][ny] == 6) {
                    break;
                }
                else {
                    check[nx][ny] += 1;
                }
                nx += dx[i]; ny += dy[i];
            }
        }
        func(level + 1);
        for (int i = 0; i < 4; i++) {
            int nx = cctvx + dx[i];
            int ny = cctvy + dy[i];
            while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (board[nx][ny] == 6) {
                    break;
                }
                else {
                    check[nx][ny] -= 1;
                }
                nx += dx[i]; ny += dy[i];
            }
        }
    }
    check[cctvx][cctvy] -= 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0 || board[i][j] == 6) continue;
            cctv.push_back({ i,j });
        }
    }
    cctvlen = cctv.size();
    func(0);
    cout << ans;
}
