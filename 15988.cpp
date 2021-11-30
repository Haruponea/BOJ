#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 1000000009;
int n, t;
long long dp[1000003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}
