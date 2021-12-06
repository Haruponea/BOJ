#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1003][10];

int sum(int idx,int s, int e) {
    int r = 0;
    for (int i = s; i < e; i++) {
        r += dp[idx][i];
    }
    return r;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = sum(i - 1, 0, j + 1)%10007;
            }
        }
    }
    cout << sum(n, 0, 10)%10007;
}
