#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, idx;
    cin >> n;
    while (n != 0)
    {
        long long ans = 0;
        stack<pair<int, int>> st; //<height, idx>
        for (int i = 0; i <= n; i++)
        {
            h = 0;
            idx = i;
            if (i != n)
                cin >> h;

            while (!st.empty() && st.top().first > h)
            {
                ans = max(ans, (long long)(st.top().first) * (i - st.top().second));
                idx = st.top().second;
                st.pop();
            }
            if (i != n)
                st.push(make_pair(h, idx));
        }

        cout << ans << '\n';
        cin >> n;
    }
}
