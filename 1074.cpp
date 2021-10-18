#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long z(long long n, long long r, long long c) {
	if (n == 0) return 1;
	long long half = pow(2, n - 1);
	if (r < half && c < half) {
		return z(n - 1, r, c);
	}
	else if (r < half && c >= half) {
		return half*half + z(n - 1, r, c - half);
	}
	else if (r >= half && c < half) {
		return half*half*2 + z(n - 1, r - half, c);
	}
	else if (r >= half && c >= half) {
		return half*half*3 + z(n - 1, r - half, c - half);
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, r, c;
	cin >> n >> r >> c;
	cout << z(n, r, c) - 1;
}
