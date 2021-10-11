#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<pair<int, int>> s;
	s.push(make_pair(100000001, 0));
	int n, idx = 1;
	cin >> n;
	while (n--) {
		int h;
		cin >> h;
		while (s.top().first < h) {
			s.pop();
		}
		cout << s.top().second << ' ';
		s.push(make_pair(h, idx++));
	}
}
