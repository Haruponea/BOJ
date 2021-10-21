#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];
void func(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i]<<' ';
		}
		cout << '\n';
		return;
	}
	int pre = -1;
	for (int i = 0; i < n; i++) {
		if (i != 0 && arr[pre] == arr[i]) continue;
		pre = i;
		ans[level] = arr[i];
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
