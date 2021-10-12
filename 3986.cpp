#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, ans = 0;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<char> st;
		for (char c : s) {
			if (c == 'A') {
				if (st.empty() || st.top() == 'B') st.push(c);
				else st.pop();
			}
			else if (c == 'B') {
				if (st.empty() || st.top() == 'A') st.push(c);
				else st.pop();
			}
		}
		if (st.empty()) {
			ans++;
		}
	}
	cout << ans;
}
