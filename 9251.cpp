#include <iostream>
#include <algorithm>
using namespace std;

string a=" ", b=" ";
int dp[1003][1003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c;
    cin >> c;
    a += c;
    cin >> c;
    b += c;

    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[a.size() - 1][b.size() - 1];
}
