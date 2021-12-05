#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
int arr[3][100003];
int dp[3][100003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                dp[i][j] = arr[i][j];
            }
        }

        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];

        for (int i = 2; i < n; i++) {
            dp[0][i] = max({ dp[1][i - 1], dp[1][i - 2] })+arr[0][i];
            dp[1][i] = max({ dp[0][i - 1], dp[0][i - 2] })+arr[1][i];
        }
        cout << max(*max_element(dp[0], dp[0] + n), *max_element(dp[1], dp[1] + n))<<'\n';
    }
}
