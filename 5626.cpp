#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// dp[i][j]는 i번째 열이 j높이일때 가능한 경우의 수

int dp[10005][5005];
int n;
int mod = 1000000007;
int arr[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > min(i, n - i - 1)) { // 불가능한 경우
            cout << 0;
            return 0;
        }
    }

    // dp initialize
    // 제일 왼쪽열은 높이 0만 가능하고 경우의 수는 1
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == -1) { // 모든 높이 가능
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            for (int j = 1; j <= min(i, n - i - 1); j++) {
                dp[i][j] = (((dp[i - 1][j - 1] + dp[i - 1][j]) % mod) +
                            dp[i - 1][j + 1]) %
                           mod;
            }
        } else { // 특정 높이만 가능
            if (arr[i] == 0)
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            else {
                dp[i][arr[i]] =
                    (((dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]]) % mod) +
                     dp[i - 1][arr[i] + 1]) %
                    mod;
            }
        }
    }
    cout << dp[n - 1][0];
}
