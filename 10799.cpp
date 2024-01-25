#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    stack<char> st;
    cin >> s;
    char pre;
    int ans = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            st.push('(');
            pre = '(';
        }
        else
        {
            if (pre == '(')
            { // 레이저라면
                st.pop();
                ans += st.size();
            }
            else
            {
                st.pop();
                ans++;
            }
            pre = ')';
        }
    }
    cout << ans;
}
