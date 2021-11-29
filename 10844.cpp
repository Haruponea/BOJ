#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[103][10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][1];
            else if (j == 9) dp[i][j] = dp[i - 1][8];
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[n][i];
        sum %= 1000000000;
    }
    cout << sum;
}
