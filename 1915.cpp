#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[1003][1003];
int arr[1003][1003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (int)(s[j - 1]-'0');
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]==0) continue;
            dp[i][j] = min({ dp[i-1][j-1],dp[i-1][j],dp[i][j-1] }) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans;
}
