#include <iostream>
#include <algorithm>
using namespace std;

bool used[10];
int n, m;
int arr[9];

void func(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i] == true) continue;
		else {
			arr[level] = i;
			used[i] = true;
			func(level + 1);
			used[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}
