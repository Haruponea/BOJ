#include <iostream>
#include <algorithm>
using namespace std;

bool board[12][12][32];
int n, m, h, ans = 5;
bool possible = false;

bool check() {
    for (int i = 0; i < n; i++) {
        int cur = i;
        for (int j = 0; j < h; j++) {
            if (cur < n - 1 && board[cur][cur + 1][j] == true) {
                cur = cur + 1;
            }
            else if (cur > 0 && board[cur][cur - 1][j] == true) {
                cur = cur - 1;
            }
        }
        if (cur != i)
            return false;
    }
    return true;
}

void func(int level, int depth, int idx) {
    if (level == depth) {
        if (possible == false) {
            possible = check();
            if (possible)
                ans = depth;
        }
            return;
    }
    for (int i = idx; i < n - 1; i++) {
        if (possible) break;
        for (int j = 0; j < h; j++) {
            if (possible) break;
            if (i == 0) {
                if (board[i][i + 1][j] == true)continue;
                else {
                    board[i][i + 1][j] = true;
                    board[i + 1][i][j] = true;
                    func(level + 1, depth, i);
                    board[i][i + 1][j] = false;
                    board[i + 1][i][j] = false;
                }
            }
            else {
                if (board[i][i - 1][j] == true || board[i][i + 1][j] == true) continue;
                else {
                    board[i][i + 1][j] = true;
                    board[i + 1][i][j] = true;
                    func(level + 1, depth, i);
                    board[i][i + 1][j] = false;
                    board[i + 1][i][j] = false;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> h;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        board[b][b + 1][a] = true;
        board[b + 1][b][a] = true;

    }
    for (int i = 0; i < 4; i++) {
        func(0, i, 0);
        if (possible) {
            cout << ans;
            return 0;
        }
    }
    cout << -1;
}
