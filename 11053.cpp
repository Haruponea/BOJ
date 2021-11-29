#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1003];
int arr[1003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n);
}
