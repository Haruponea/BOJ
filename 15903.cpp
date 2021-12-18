#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long arr[1003];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    

    for (int i = 0; i < m; i++) {
        sort(arr, arr + n);
        long long tmp = arr[0] + arr[1];
        arr[0] = tmp; arr[1] = tmp;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    cout << sum;
}
