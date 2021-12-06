#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[103];
int dp[10003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    dp[0] = 1;
        for (int j = 0; j < n; j++){
            for (int i = 1; i <= k; i++) {
                if (i - arr[j] < 0) continue;
                else {
                    dp[i] += dp[i - arr[j]];
                }
            }
        }
    cout << dp[k];
}
