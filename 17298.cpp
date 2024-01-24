#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[1000002];
    fill(arr, arr + 1000002, -1);
    int n, k;
    stack<pair<int, int>> st; // pair<num,idx>
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        while (!st.empty() && st.top().first < k)
        {
            arr[st.top().second] = k;
            st.pop();
        }
        st.push(make_pair(k, i));
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
