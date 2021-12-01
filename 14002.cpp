#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dp[1003];
int arr[1003];
int path[1003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (dp[i] < dp[j] + 1) {
                    path[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int idx = max_element(dp + 1, dp + n + 1) - dp;
    vector<int> v;
    while (idx != 0) {
        v.push_back(arr[idx]);
        idx = path[idx];
    }
    cout << v.size() << '\n';
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i]<<' ';
    }
}
