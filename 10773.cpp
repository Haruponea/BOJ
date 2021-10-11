#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	stack<int> s;
	while (k--) {
		int n;
		cin >> n;
		if (n != 0) {
			s.push(n);
		}
		else
			s.pop();
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}
