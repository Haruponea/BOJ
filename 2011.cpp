#include <iostream>
#include <algorithm>
using namespace std;

string s=" ";
int dp[5003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool possible = true;
    string c;
    cin >> c;
    s += c;
    if (s[1] == '0') possible = false;
    else dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; possible && i < s.size(); i++) {
        if (s[i] != '0')
            dp[i] += dp[i - 1];

        if (s[i - 1] == '1') dp[i] += dp[i - 2];
        else if (s[i - 1] == '2')
            if (s[i] >= '0' && s[i] <= '6') dp[i] += dp[i - 2];
        else if (s[i] == '0' && s[i - 1] == '0')
            possible = false;
        dp[i] %= 1000000;
    }
    if (possible) cout << dp[s.size() - 1];
    else cout << 0;
}
