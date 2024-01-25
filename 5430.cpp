#include <bits/stdc++.h>
using namespace std;

void get_dq(deque<int> &dq, string &s)
{
    int temp = 0;
    for (char c : s)
    {
        if ('0' <= c && c <= '9')
        {
            temp *= 10;
            temp += (int)(c - '0');
        }
        else if (c == ',' || c == ']')
        {
            if (temp != 0)
                dq.push_back(temp);
            temp = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    string order, arr;
    cin >> n;
    while (n--)
    {
        int is_reverse = 0, is_error = 0;
        cin >> order >> l >> arr;
        deque<int> dq;
        get_dq(dq, arr);
        for (char c : order)
        {
            if (c == 'R')
            {
                is_reverse = 1 - is_reverse;
            }
            else
            {
                if (is_reverse == 0)
                {
                    if (dq.empty())
                    {
                        is_error = 1;
                        break;
                    }
                    else
                        dq.pop_front();
                }
                else
                {
                    if (dq.empty())
                    {
                        is_error = 1;
                        break;
                    }
                    else
                        dq.pop_back();
                }
            }
        }
        if (is_error)
            cout << "error\n";
        else
        {
            cout << '[';
            if (is_reverse == 1)
            {
                reverse(dq.begin(), dq.end());
            }
            while (!dq.empty())
            {
                cout << dq.front();
                if (dq.size() != 1)
                    cout << ',';
                dq.pop_front();
            }
            cout << "]\n";
        }
    }
}
