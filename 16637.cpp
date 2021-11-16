#include <iostream>
#include <algorithm>
using namespace std;

int n, ans=-(1<<31);
string s;
int calc(int a, char oper, int b) {
    if (oper == '+') return a + b;
    else if (oper == '-') return a - b;
    else return a * b;
}

void func(int idx, int result) {
    if (idx >= n - 1) {
        ans = max(ans, result);
        return;
    }
    int tmp = calc(result, s[idx + 1], s[idx + 2]-'0');
    func(idx+2, tmp);
    if (idx < n - 4){
        int tmp = calc(s[idx + 2] - '0', s[idx + 3], s[idx + 4] - '0');
        int tmpp = calc(result, s[idx + 1], tmp);
        func(idx + 4, tmpp);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> s;
    
    func(0, s[0]-'0');
    cout << ans;
}
