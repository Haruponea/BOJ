#include <bits/stdc++.h>
using namespace std;

bool is_good(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == 'A')
        {
            if (!st.empty() && st.top() == 'A')
                st.pop();
            else
                st.push('A');
        }
        else
        {
            if (!st.empty() && st.top() == 'B')
                st.pop();
            else
                st.push('B');
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

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (is_good(s))
            sum++;
    }
    cout << sum;
}
