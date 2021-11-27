#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000006];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a = 1000006, b = 1000006, c = dp[i - 1];
        if (i % 3 == 0) {
            a = dp[i / 3];
        }
        if (i % 2 == 0) {
            b = dp[i / 2];
        }
        dp[i] = min(a, min(b, c)) + 1;
    }
    cout << dp[n];
}
