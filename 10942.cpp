#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[2003];
int dp[2003][2003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i < n - 1 && arr[i] == arr[i + 1])
            dp[i][i + 1] = 1;
    }
    for (int d = 3; d <= n; d++) {
        for (int i = 0; i < n - d + 1; i++) {
            if (arr[i] == arr[i + d - 1] && dp[i + 1][i + d - 2] == 1) {
                dp[i][i + d - 1] = 1;
            }
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << dp[a-1][b-1]<<'\n';
    }
}
