#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1003];
int dp[1003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[i - j]+arr[j]);
        }
    }
    cout << dp[n];
}
