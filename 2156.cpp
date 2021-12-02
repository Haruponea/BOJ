#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[10003][3];
int arr[10003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[1][1] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = *max_element(dp[i - 1], dp[i - 1] + 3);
        dp[i][1] = arr[i] + dp[i - 1][0];
        dp[i][2] = arr[i] + dp[i - 1][1];
    }
    cout << *max_element(dp[n], dp[n] + 3);
}
