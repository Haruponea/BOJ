#include <iostream>
#include <algorithm>
using namespace std;

int dp[302][3];
int arr[302];
int n;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1][1] = arr[1];
    dp[2][1] = arr[2];
    dp[2][2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i];
    }
    cout << max(dp[n][1],dp[n][2]);
}
