/*
https://www.acmicpc.net/problem/2042
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, k;
long long tree[1 << 21];
long long leafStart = 1 << 20;

void update(long long idx, long long data) {
    idx += leafStart;
    tree[idx] = data;
    while (idx > 1) {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

long long get(long long l, long long r) {
    l += leafStart;
    r += leafStart;
    long long ret = 0;
    while (l <= r) {
        if (l % 2 == 1)
            ret += tree[l++];
        if (r % 2 == 0)
            ret += tree[r--];
        l /= 2;
        r /= 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> tree[i + leafStart];

    for (int i = leafStart - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    long long a, b, c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        } else if (a == 2) {
            cout << get(b - 1, c - 1) << '\n';
        }
    }
}
