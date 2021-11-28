#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> dp[42];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = { 1,0 };
    dp[1] = { 0,1 };
    for (int i = 2; i <= 40; i++) {
        dp[i] = { dp[i - 1].first + dp[i - 2].first,dp[i - 1].second + dp[i - 2].second };
    }

    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << dp[a].first << ' ' << dp[a].second<<'\n';
    }
}
