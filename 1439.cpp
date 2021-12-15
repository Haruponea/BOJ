#include <iostream>
#include <algorithm>
using namespace std;

string s;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    char n;
    n = '1' - s[s.size() - 1] + '0';
    s += n;
    int num0 = 0, num1 = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i - 1] == '0') {
                num0++;
            }
            else {
                num1++;
            }
        }
    }
    cout << min(num0, num1);
}
