#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[100003];
int arr[100003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        if (arr[i] + dp[i - 1] < arr[i]) dp[i] = arr[i];
        else dp[i] = arr[i] + dp[i - 1];
    }
    cout << *max_element(dp + 1, dp + n + 1);
}
