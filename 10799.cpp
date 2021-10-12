#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	char pre = ')';
	string s;
	stack<char> st;
	cin >> s;
	for (char c : s) {
		if (c == '(') {
			st.push(c);
			pre = c;
		}
		else {
			if (pre == '(') {
				st.pop();
				ans += st.size();
				pre = ')';
			}
			else {
				st.pop();
				ans += 1;
				pre = ')';
			}
		}
	}
	cout << ans;
}
