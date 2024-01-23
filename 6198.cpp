#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int n, k;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        while (!s.empty() && s.top() <= k)
            s.pop();
        sum += s.size();
        s.push(k);
    }
    cout << sum;
}
