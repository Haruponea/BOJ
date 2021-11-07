#include <iostream>
#include <algorithm>
using namespace std;

int board[502][502];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0) {
                board[i][j] = board[i][j] + board[i - 1][j];
            }
            else if (j == i - 1) {
                board[i][j] = board[i][j] + board[i - 1][j - 1];
            }
            else {
                board[i][j] = max(board[i][j] + board[i - 1][j], board[i][j] + board[i - 1][j - 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, board[n][i]);
    }
    cout << ans;
}
