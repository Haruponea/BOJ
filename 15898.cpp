#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
pair<int, char> board[5][5];
pair<int, char> prepare[12][4][4][4];
pair<int, char> boardcopy[5][5];
int idx[3];
bool isused[12];

void rotate(int i,int dir) {
    pair<int, char>tmp[4][4];
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            tmp[a][b] = prepare[i][dir-1][3 - b][a];
        }
    }
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            prepare[i][dir][a][b] = tmp[a][b];
        }
    }
}

void solve() {
    for (int tmp = 0; tmp < 64; tmp++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                boardcopy[i][j] = board[i][j];
            }
        }
        int tmpcopy = tmp;
        int dirarr[3];
        for (int i = 0; i < 3; i++) {
            int dir = tmpcopy % 4;
            tmpcopy /= 4;
            dirarr[i] = dir;
        }
        for (int x1 = 0; x1 < 2; x1++) {
            for (int y1 = 0; y1 < 2; y1++) {
                for (int x2 = 0; x2 < 2; x2++) {
                    for (int y2 = 0; y2 < 2; y2++) {
                        for (int x3 = 0; x3 < 2; x3++) {
                            for (int y3 = 0; y3 < 2; y3++) {

                                for (int i = 0; i < 5; i++) {
                                    for (int j = 0; j < 5; j++) {
                                        boardcopy[i][j] = board[i][j];
                                    }
                                }

                                for (int a = 0; a < 4; a++) {
                                    for (int b = 0; b < 4; b++) {
                                        if (prepare[idx[0]][dirarr[0]][a][b].second != 'W') {
                                            boardcopy[x1 + a][y1 + b].second = prepare[idx[0]][dirarr[0]][a][b].second;
                                        }
                                        boardcopy[x1 + a][y1 + b].first += prepare[idx[0]][dirarr[0]][a][b].first;
                                        if (boardcopy[x1 + a][y1 + b].first < 0)  boardcopy[x1 + a][y1 + b].first = 0;
                                        else if (boardcopy[x1 + a][y1 + b].first > 9) boardcopy[x1 + a][y1 + b].first = 9;
                                    }
                                }
                                for (int a = 0; a < 4; a++) {
                                    for (int b = 0; b < 4; b++) {
                                        if (prepare[idx[1]][dirarr[1]][a][b].second != 'W') {
                                            boardcopy[x2 + a][y2 + b].second = prepare[idx[1]][dirarr[1]][a][b].second;
                                        }
                                        boardcopy[x2 + a][y2 + b].first += prepare[idx[1]][dirarr[1]][a][b].first;
                                        if (boardcopy[x2 + a][y2 + b].first < 0)  boardcopy[x2 + a][y2 + b].first = 0;
                                        else if (boardcopy[x2 + a][y2 + b].first > 9) boardcopy[x2 + a][y2 + b].first = 9;
                                    }
                                }
                                for (int a = 0; a < 4; a++) {
                                    for (int b = 0; b < 4; b++) {
                                        if (prepare[idx[2]][dirarr[2]][a][b].second != 'W') {
                                            boardcopy[x3 + a][y3 + b].second = prepare[idx[2]][dirarr[2]][a][b].second;
                                        }
                                        boardcopy[x3 + a][y3 + b].first += prepare[idx[2]][dirarr[2]][a][b].first;
                                        if (boardcopy[x3 + a][y3 + b].first < 0)  boardcopy[x3 + a][y3 + b].first = 0;
                                        else if (boardcopy[x3 + a][y3 + b].first > 9) boardcopy[x3 + a][y3 + b].first = 9;
                                    }
                                }
                                int r = 0, b = 0, g = 0, y = 0;
                                for (int i = 0; i < 5; i++) {
                                    for (int j = 0; j < 5; j++) {
                                        if (boardcopy[i][j].second == 'R') r += boardcopy[i][j].first;
                                        else if (boardcopy[i][j].second == 'B') b += boardcopy[i][j].first;
                                        else if (boardcopy[i][j].second == 'G') g += boardcopy[i][j].first;
                                        else if (boardcopy[i][j].second == 'Y') y += boardcopy[i][j].first;
                                    }
                                }
                                ans = max(ans, (7 * r) + (5 * b) + (3 * g) + (2 * y));
                                //cout << r << ' ' << b << ' ' << g << ' ' << y << '\n';
                            }
                        }
                    }
                }
            }
        }
    }
}

void tracking(int level) {
    if (level == 3) {
        solve();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isused[i] == true) continue;
        isused[i] = true;
        idx[level] = i;
        tracking(level + 1);
        isused[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) fill(board[i], board[i] + 5, make_pair( 0,'W' ));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                cin >> prepare[i][0][a][b].first;
            }
        }
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                cin >> prepare[i][0][a][b].second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int dir = 0; dir < 4; dir++) {
            if(dir!=0)
                rotate(i, dir);
        }
    }
    tracking(0);
    cout << ans;
}
