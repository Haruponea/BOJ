#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];
void func(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[ans[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = (level == 0) ? 0 : ans[level - 1] + 1;
	for (int i = tmp; i < n; i++) {
		ans[level] = i;
		func(level + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);
}
