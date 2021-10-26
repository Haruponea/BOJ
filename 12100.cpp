#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int n, ans;
bool did[22][22];
int board1[22][22];
int board2[22][22];
int board[22][22];
void rotate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board2[i][j] = board1[n - 1 - j][i];
        }
    }
    swap(board1, board2);
}

void push(int dir) {
    for (int i = 0; i < dir; i++) rotate();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board1[i][j] == 0) continue;
            int cx = i;
            int cy = j;
            int nx = i - 1;
            int ny = j;
            while (true) {
                if (nx < 0) break;
                else {
                    if (board1[nx][ny] == 0) {
                        board1[nx][ny] = board1[cx][cy];
                        board1[cx][cy] = 0;
                        cx = nx;
                        nx -= 1;
                    }
                    else if (board1[nx][ny] == board1[cx][cy] && did[nx][ny]==false) {
                        board1[nx][ny] *= 2;
                        did[nx][ny] = true;
                        board1[cx][cy] = 0;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 4 - dir; i++) rotate();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int tmp = 0; tmp < (1 << (2 * 5)); tmp++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board1[i][j] = board[i][j];
        int brute = tmp;
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            push(dir);
            for (int i = 0; i < 20; i++) {
                fill(did[i], did[i] + 20, false);
            }
        }
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m = max(m, board1[i][j]);
            }
        }
        ans = max(m, ans);
    }
    cout << ans;
}
