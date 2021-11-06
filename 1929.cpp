#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    arr[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == 1) continue;
        for (int j = 2; j * i <= n; j++) {
            arr[j * i] = 1;
        }
    }
    for (int i = m; i <= n; i++) {
        if (arr[i] == 0) cout << i<<'\n';
    }
}
