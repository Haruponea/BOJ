#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int n, k, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 0)
            st.pop();
        else
            st.push(k);
    }
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum;
}
