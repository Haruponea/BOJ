#include <iostream>
#include <algorithm>
using namespace std;

int n = 10;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int a = st;
    int b = mid;
    for (int idx = st; idx < en; idx++) {
        if (a == mid) tmp[idx] = arr[b++];
        else if (b == en) tmp[idx] = arr[a++];
        else if (arr[a] <= arr[b]) tmp[idx] = arr[a++];
        else tmp[idx] = arr[b++];
    }
    for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (st + 1 == en) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}
