#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[100003] = {};  // check위한 배열
    int nums[100003] = {}; // 입력되는 배열 저장
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nums[i] = k;
        arr[k]++;
    }
    int x;
    cin >> x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - nums[i] > 0 && x - nums[i] < 100000 && arr[x - nums[i]] == 1)
            sum += 1;
    }
    cout << sum / 2;
}
