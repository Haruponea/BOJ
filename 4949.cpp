#include <bits/stdc++.h>
using namespace std;

bool is_balanced(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '[' || c == '(')
            st.push(c);
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;
            else
                st.pop();
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);
    while (s.compare("."))
    {
        if (is_balanced(s))
            cout << "yes\n";
        else
            cout << "no\n";
        getline(cin, s);
    }
}
