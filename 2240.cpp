#include <iostream>
#include <algorithm>
using namespace std;

int t, w;
int dp[1003][3][32];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        int a;
        cin >> a;
        a--;
        if (i == 1) {
            if (a == 0) dp[1][0][0] = 1;
            else dp[1][1][1] = 1;
        }
        else {
            for (int j = 0; j <= w; j++) {
                if (j == 0) {
                    if(a==0)
                        dp[i][a][j] = dp[i - 1][a][j] + 1;
                }
                else {
                    dp[i][a][j] = max(dp[i - 1][a][j], dp[i - 1][1-a][j - 1]) + 1;
                    dp[i][1-a][j] = max(dp[i - 1][a][j - 1], dp[i - 1][1-a][j]);
                }
            }
        }
    }
    cout << max(*max_element(dp[t][0], dp[t][0] + w + 1), *max_element(dp[t][1], dp[t][1] + w + 1));
}
