#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

pair<int, int> hilbert(int n, int m) {
	if (n == 2) {
		if (m == 0) {
			return { 1,1 };
		}
		else if (m == 1) {
			return { 1,2 };
		}
		else if (m == 2) {
			return { 2,2 };
		}
		else if (m == 3) {
			return { 2,1 };
		}
	}
	else {
		int half = n / 2;
		int quadrant = m / (half*half);
		if (quadrant == 0) {
			pair<int, int> p = hilbert(half, m % (half * half));
			swap(p.first, p.second);
			return p;
		}
		else if (quadrant == 1) {
			pair<int, int> p = hilbert(half, m % (half * half));
			p.second += half;
			return p;
		}
		else if (quadrant == 2) {
			pair<int, int> p = hilbert(half, m % (half * half));
			p.first += half;
			p.second += half;
			return p;
		}
		else if (quadrant == 3) {
			pair<int, int> p = hilbert(half, m % (half * half));
			pair<int, int> tmp = { n - p.second + 1, half - p.first + 1 };
			return tmp;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	pair<int, int> ans = hilbert(n, m - 1);
	cout << ans.first << ' ' << ans.second;
}
