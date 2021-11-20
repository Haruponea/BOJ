#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, string> p[100002];
pair<int, string> tmp[100002];
void merge(int st, int en) {
    int mid = (st + en) / 2;
    int aidx = st;
    int bidx = mid;
    for (int i = st; i < en; i++) {
        if (aidx == mid) tmp[i] = p[bidx++];
        else if (bidx == en) tmp[i] = p[aidx++];
        else if (p[aidx].first <= p[bidx].first) tmp[i] = p[aidx++];
        else tmp[i] = p[bidx++];
    }
    for (int i = st; i < en; i++) {
        p[i] = tmp[i];
    }
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
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        p[i] = { age,name };
    }
    merge_sort(0, n);
    for (int i = 0; i < n; i++) {
        cout << p[i].first << ' ' << p[i].second << '\n';
    }
}
