#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1] = 1;
    dp[3] = 1;
    dp[4] = 1;

    for (int i = 5; i <= n; i++) {
        if (dp[i - 1] == false || dp[i - 3] == false || dp[i - 4] == false)
            dp[i] = true;
    }
    if (dp[n]) cout << "SK";
    else cout << "CY";
}
