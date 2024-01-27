#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L, num, start;
    cin >> N >> L;
    deque<pair<int, int>> dq; //<number, idx>
    for (int i = 1; i <= N; i++)
    {
        start = i - L + 1;
        if (start < 1)
            start = 1;
        cin >> num;
        while (!dq.empty() && dq.back().first > num)
            dq.pop_back();
        if (!dq.empty() && dq.front().second < start)
            dq.pop_front();
        dq.push_back(make_pair(num, i));
        cout << dq.front().first << ' ';
    }
}
