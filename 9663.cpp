#include <iostream>
#include <algorithm>
using namespace std;

bool used1[15];
bool used2[30];
bool used3[30];
int n, cnt;
int arr[9];

void func(int level) {
	if (level == n ) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used1[i] == false && used2[level + i] == false && used3[level - i + n - 1] == false) {
			used1[i] = true;
			used2[level + i] = true;
			used3[level - i + n - 1] = true;
			func(level + 1);
			used1[i] = false;
			used2[level + i] = false;
			used3[level - i + n - 1] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;
}
