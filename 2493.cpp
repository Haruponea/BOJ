#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, sum = 0;
    stack<pair<int, int>> st; // pair<index, height>
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        while (!st.empty() && st.top().second < k)
        {
            st.pop();
        }
        if (st.empty())
            cout << 0 << ' ';
        else
            cout << st.top().first << ' ';
        st.push(make_pair(i, k));
    }
}
