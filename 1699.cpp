#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[100003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
        dp[i] = 1000000;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
}
