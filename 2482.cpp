#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][1002];
int n, k;
int mod = 1000000003;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i-1][j]+dp[i-2][j-1]) % mod;
        }
    }
    cout << (dp[n-1][k]+dp[n-3][k-1]) % mod;
}
