#include <bits/stdc++.h>
using namespace std;

bool is_possible(string &s1, string &s2)
{
    int arr1[26] = {};
    int arr2[26] = {};
    for (char c : s1)
    {
        arr1[c - 'a']++;
    }
    for (char c : s2)
    {
        arr2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (is_possible(s1, s2))
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}
