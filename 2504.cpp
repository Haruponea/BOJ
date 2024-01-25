#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    long long ans = 0;
    long long temp = 1;

    char pre = '.';
    for (char c : s)
    {
        if (c == '(')
        {
            st.push(c);
            temp *= 2;
        }
        else if (c == '[')
        {
            st.push(c);
            temp *= 3;
        }
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                ans = 0;
                break;
            }
            else
            {
                st.pop();
                if (pre == '(')
                    ans += temp;
                temp /= 2;
            }
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                ans = 0;
                break;
            }
            else
            {
                st.pop();
                if (pre == '[')
                    ans += temp;
                temp /= 3;
            }
        }
        pre = c;
    }
    if (st.empty())
        cout << ans;
    else
        cout << 0;
}
