#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w = 1, ans = 0;
	char pre;
	string s;
	cin >> s;
	stack<char> st;
	for (char c : s) {
		if (c == '(') {
			w *= 2;
			st.push(c);
			pre = '(';
		}
		else if (c == '[') {
			w *= 3;
			st.push(c);
			pre = '[';
		}
		else if (c == ')') {
			if (st.empty() || st.top() == '[') {
				cout << 0;
				return 0;
			}
			else {
				st.pop();
				if(pre =='(')
					ans += w;
				w /= 2;
			}
			pre = ')';
		}
		else if (c == ']') {
			if (st.empty() || st.top() == '(') {
				cout << 0;
				return 0;
			}
			else {
				st.pop();
				if(pre =='[')
					ans += w;
				w /= 3;
			}
			pre = ']';
		}
	}
	if (st.empty()) {
		cout << ans;
	}
	else cout << 0;
}
