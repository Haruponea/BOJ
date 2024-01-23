#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, num = 1;
    cin >> n;
    vector<char> ans;
    stack<int> st;

    while (n--)
    {
        cin >> k;
        if (st.empty())
        {
            ans.push_back('+');
            st.push(num++);
        }
        while (st.top() < k)
        {
            st.push(num++);
            ans.push_back('+');
        }
        if (st.top() == k)
        {
            ans.push_back('-');
            st.pop();
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    for (char c : ans)
        cout << c << '\n';
}
