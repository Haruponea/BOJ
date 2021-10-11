#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> s;
	long n, ans = 0;
	cin >> n;
	while (n--) {
		int h;
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop();
		}
		ans += s.size();
		s.push(h);
	}
	cout << ans;
}
