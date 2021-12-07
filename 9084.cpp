#include <iostream>
#include <algorithm>
using namespace std;

int t;
int arr[23];
int dp[10003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        cin >> target;
        fill(dp, dp + 10003, 0);
        for (int i = 0; i < n; i++) {
            dp[arr[i]] += 1;
            for (int j = 1; j <= target; j++) {
                if (j - arr[i] < 0) continue;
                dp[j] += dp[j - arr[i]];
            }
        }
        cout << dp[target] << '\n';
    }
}
