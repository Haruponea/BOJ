#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    list<int> l;
    cout << "<";
    for (int i = 1; i <= n; i++)
        l.push_back(i);
    auto t = l.begin();
    while (!l.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            t++;
            if (t == l.end())
                t = l.begin();
        }
        cout << *t;
        t = l.erase(t);
        if (t == l.end())
            t = l.begin();
        if (!l.empty())
            cout << ", ";
        else
            cout << '>';
    }
}
