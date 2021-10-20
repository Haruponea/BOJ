#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
void func(int level, int mx) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = mx + 1; i <= n; i++) {
		arr[level] = i;
		func(level + 1, i);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	func(0, 0);
}
