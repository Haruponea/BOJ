#include <iostream>
#include <algorithm>
using namespace std;

int n, s, cnt;
int arr[22];

void func(int level, int total) {
	if (level == n) {
		if (total == s) cnt++;
		return;
	}
	func(level + 1, total);
	func(level + 1, total + arr[level]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}
