#include <iostream>
#include <algorithm>
using namespace std;

int a[20003];
int b[20003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a, a+n);
        sort(b, b+m);
        int bidx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (bidx < m && b[bidx] < a[i])bidx++;
            ans += bidx;
        }
        cout << ans<<'\n';
    }
}
