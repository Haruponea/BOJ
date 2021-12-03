#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[43];
bool vip[43];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        vip[a] = true;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int idx = 0, ans = 1;
    for (int i = 1; i <= n+1; i++) {
        if (i == n + 1) {
            ans *= dp[i - idx - 1];
        }
        else if (vip[i] == true) {
            ans *= dp[i - idx - 1];
            idx = i;
        }
    }
    cout << ans;
}
