#include <iostream>
#include <algorithm>
using namespace std;

int arr[14];
int ans[7];
int k=1;

void func(int level,int st) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i]<<' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = st + 1; i < k; i++) {
		ans[level] = arr[i];
		func(level + 1, i);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		func(0, -1);
		cout << '\n';
	}
}	
