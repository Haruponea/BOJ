#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int cnt[18][18][3];
int board[18][18];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    cnt[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (board[i][j] == 1) continue;
            cnt[i][j][0] += cnt[i][j - 1][0];
            cnt[i][j][0] += cnt[i][j - 1][2];
            cnt[i][j][1] += cnt[i - 1][j][1];
            cnt[i][j][1] += cnt[i - 1][j][2];
            if (i != 1) {
                if (board[i-1][j] != 1 && board[i][j-1] != 1) {
                    cnt[i][j][2] += cnt[i-1][j-1][0];
                    cnt[i][j][2] += cnt[i-1][j-1][1];
                    cnt[i][j][2] += cnt[i-1][j-1][2];
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += cnt[n][n][i];
    }
    cout << sum;
}
