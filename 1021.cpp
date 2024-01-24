#include <bits/stdc++.h>

using namespace std;

int get_idx(deque<int>& dq, int num) {
	int idx = 0;
	while (dq[idx] != num) {
		idx++;
	}
	return idx;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	vector<int> v;
	while (m--) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	int ans = 0;
	for (int target : v) {
		int idx = get_idx(dq, target);
		if (idx <= dq.size() / 2) {
			for (int i = 0; i < idx; i++) {
				ans++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < dq.size() - idx; i++) {
				ans++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		dq.pop_front();
	}cout << ans;
}
