#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long ans=0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int min = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (min > arr[i]) {
                ans += min - arr[i];
            }
            else min = arr[i];
        }
        cout << ans << '\n';
    }
}
