#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[1002];//{weight, time};
int n, w, l, st, e, totalw, ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = { a,0 };
    }
    st = 0; e = 0;
    while (st < n) {
        ans++;
        for (int i = st; i < e; i++) {
            arr[i].second += 1;
            if (arr[i].second >= w) {
                totalw -= arr[st++].first;
            }
        }
        if (e < n && totalw + arr[e].first <= l) {
            totalw += arr[e++].first;
        }
    }
    cout << ans;
}
