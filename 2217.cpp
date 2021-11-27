#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    int w = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        w = arr[n - 1 - i] * cnt;
        ans = max(ans, w);
    }
    cout << ans;
}
