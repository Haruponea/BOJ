#include <iostream>
#include <algorithm>
using namespace std;

int k, c= 1;
int arr[100003][3];
int dp[100003][3];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    while (k != 0) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> arr[i][j];
            }
        }
        dp[0][0] = 100000000, dp[0][1] = arr[0][1], dp[0][2] = arr[0][1] + arr[0][2];
        for (int i = 1; i < k; i++) {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
                dp[i][1] = min({ dp[i][0], dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] })+arr[i][1];
                dp[i][2] = min({ dp[i][1], dp[i - 1][1], dp[i - 1][2] }) + arr[i][2];
        }
        cout << c << ". " << dp[k - 1][1] << '\n';
        c++;
        cin >> k;
    }
}
