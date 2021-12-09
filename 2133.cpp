#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[32];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i+=2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j+=2) {
            dp[i] += dp[i - j] * 2;
        }
    }
    cout << dp[n];
}
