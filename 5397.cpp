#include <bits/stdc++.h>
using namespace std;

void get_password(string &s, list<char> &lst)
{
    list<char>::iterator t = lst.begin();
    for (char c : s)
    {
        if (c == '<')
        {
            if (t != lst.begin())
            {
                t--;
            }
        }
        else if (c == '>')
        {
            if (t != lst.end())
            {
                t++;
            }
        }
        else if (c == '-')
        {
            if (t != lst.begin())
            {
                t--;
                t = lst.erase(t);
            }
        }
        else
        {
            lst.insert(t, c);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        list<char> lst;
        get_password(s, lst);
        for (char c : lst)
            cout << c;
        cout << '\n';
    }
}
