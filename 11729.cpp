#include <iostream>
#include <algorithm>
using namespace std;

void hanoi(int from, int by, int to, int n) {
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}
	hanoi(from, to, by, n - 1);
	hanoi(from, by, to, 1);
	hanoi(by, from, to, n - 1);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(1, 2, 3, n);
}
