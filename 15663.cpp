#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];
int pre[9];
bool isused[9];
void func(int level) {
	if (level == m) {
		bool possible = false;
		for (int i = 0; i < m; i++) {
			if (ans[i] != pre[i]) {
				possible = true;
				break;
			}
		}
		if (possible) {
			for (int i = 0; i < m; i++) {
				cout << ans[i] << ' ';
				pre[i] = ans[i];
			}
			cout << '\n';
		}
	}
	int prenum = 0;
	for (int i = 0; i < n; i++) {
		if (isused[i] == true || prenum == arr[i]) continue;
		isused[i] = true;
		prenum = arr[i];
		ans[level] = arr[i];
		func(level + 1);
		isused[i] = false;
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
