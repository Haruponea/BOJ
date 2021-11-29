#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[103];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = (long long)1;
    dp[2] = (long long)1;
    dp[3] = (long long)1;
    dp[4] = (long long)2;
    dp[5] = (long long)2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        cout << dp[k]<<'\n';
    }
}
