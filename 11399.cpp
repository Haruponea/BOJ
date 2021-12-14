#include <iostream>
#include <algorithm>
using namespace std;

int arr[1003];
int dp[1003];
int n;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int sum = 0;
    dp[0] = arr[0];
    sum += arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
        sum += dp[i];
    }

    cout <<sum;
}
