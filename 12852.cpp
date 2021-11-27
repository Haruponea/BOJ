#include <iostream>
#include <algorithm>
using namespace std;

int n;
int path[1000003];
int dp[1000003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        path[i] = i - 1;
        if (i % 3 == 0 && dp[i]> dp[i/3]+1) {
            dp[i] = dp[i / 3] + 1;
            path[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            path[i] = i / 2;
        }
    }
    cout << dp[n] << '\n';
    int cur = n;
    while (cur != 0) {
        cout << cur<<' ';
        cur = path[cur];
    }
}
