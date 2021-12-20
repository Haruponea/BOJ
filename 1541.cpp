#include <iostream>
#include <algorithm>
using namespace std;

string s;
int ans;
int tmp;
bool pre = false;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for (int i = 0; i <= s.size(); i++) {
        if (i==s.size() || s[i] == '+' || s[i] == '-') {
            if (pre == true)
                ans += tmp * -1;
            else 
                ans += tmp;
            if (s[i] == '-') pre = true;
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += s[i] - '0';
        }
    }
    cout << ans;
}
