#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <climits>

using namespace std;
int leafStart = (1 << 20);
int tree[(1 << 21)];

void update(int idx, int data) {
	idx += leafStart - 1;
	tree[idx] += data;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

int get(int idx, int cur) {
	if (cur >= leafStart) {
		update(cur - leafStart+1, -1);
		return cur - leafStart + 1;
	}
	if (tree[cur * 2] >= idx) {
		return get(idx, cur*2);
	}
	else {
		idx -= tree[cur * 2];
		return get(idx, cur*2+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout<<get(b,1)<<'\n';
		}
		else {
			cin >> b >> c;
			update(b, c);
		}
	}
}
