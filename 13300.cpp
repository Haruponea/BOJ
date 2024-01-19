#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int arr[2][6] = {};
    int s, g;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> g;
        arr[s][g - 1]++;
    }
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] % k == 0)
                sum += arr[i][j] / k;
            else
                sum += ((arr[i][j] / k) + 1);
        }
    }
    cout << sum;
}
