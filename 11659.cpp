#include <iostream>
#include <algorithm>
using namespace std;

int n, m ;
int arr[100003];
int dp[100003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a - 1]<<'\n';
    }
}
