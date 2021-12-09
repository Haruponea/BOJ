#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[103];
int dp[10003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dp, dp + 10003, 1000000);
    dp[0] = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
        }
    }
    if (dp[k] == 1000000) dp[k] = -1;
    cout << dp[k];
}
