#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;

	int arr1[26] = {};
	int arr2[26] = {};
	for (char c : s1) {
		arr1[c - 'a']++;
	}
	for (char c : s2) {
		arr2[c - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans += abs(arr1[i] - arr2[i]);
	}
	cout << ans;
}
