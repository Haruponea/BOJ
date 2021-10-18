#include <iostream>
#include <algorithm>
using namespace std;

long long A, B, C;

long long pow(long long a, long long b, long long m) {
	if (b == 1) {
		return a % m;
	}
	long long val = pow(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0) return val;
	return val * a % m;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, m;
	cin >> a >> b >> m;
	cout << pow(a, b, m);
}
