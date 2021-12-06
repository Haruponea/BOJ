#include <iostream>
#include <algorithm>
using namespace std;

int n, mod = 1000000000;
int dp[2000003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1000001] = 1;
    cin >> n;
    for (int i = 1000002; i <= 2000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%mod;
    }
    for (int i = 999999; i >= 0; i--) {
        dp[i] = (dp[i + 2] - dp[i + 1])%mod;
    }
    if (dp[n + 1000000] > 0) cout << 1 << '\n';
    else if (dp[n + 1000000] == 0) cout << 0 << '\n';
    else cout << "-1\n";
    cout << abs(dp[n + 1000000]);
}
