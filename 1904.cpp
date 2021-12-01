#include <iostream>
#include <algorithm>
using namespace std;

int mod = 15746;
int n;
int dp[1000003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%mod;
    }
    cout << dp[n];
}
