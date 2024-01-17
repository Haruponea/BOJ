#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result = 1, k;
    int arr[10];
    fill(arr, arr + 10, 0);
    for (int i = 0; i < 3; i++)
    {
        cin >> k;
        result *= k;
    }
    while (result != 0)
    {
        arr[result % 10]++;
        result /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << '\n';
}
