#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + n);
    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t > arr[i].second) continue;
        ans++;
        t = arr[i].first;
    }
    cout << ans;
}
