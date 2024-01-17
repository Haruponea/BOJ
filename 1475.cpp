#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int arr[10];
    fill(arr, arr + 10, 0);
    cin >> n;
    while (n != 0)
    {
        arr[n % 10]++;
        n /= 10;
    }
    int max = (arr[6] + arr[9] + 1) / 2;
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        if (max < arr[i])
            max = arr[i];
    }
    cout << max;
}
