#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[15];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt=0;
    for (int i = n - 1; i >= 0; i--) {
        cnt += k / a[i];
        k %= a[i];
    }
    cout << cnt;
}
