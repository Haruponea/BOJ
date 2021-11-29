#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[17];
int dp[17];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        dp[i] = arr[i].second;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (j + arr[j].first <= i) {
                dp[i] = max(dp[i], dp[j] + arr[i].second);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i + arr[i].first <= n+1) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans;
}
