#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char arr[16];
char ans[16];

void func(int level,int st) {
	if (level == l) {
		int mo = 0;
		for (int i = 0; i < l; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				mo++;
		}
		if (mo >= 1 && l - mo >= 2) {
			for (int i = 0; i < l; i++) {
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = st + 1; i < c; i++) {
		ans[level] = arr[i];
		func(level + 1, i);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	func(0, -1);
}	
