#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		bool possible = true;
		string s;
		stack<char> st;
		getline(cin, s);
		if (s == ".") {
			break;
		}
		else {
			for (char c : s) {
				if (c == '(' || c == '[') st.push(c);
				else if (c == ')') {
					if (st.empty() || st.top() == '[') {
						possible = false;
						break;
					}
					else {
						st.pop();
					}
				}
				else if (c == ']') {
					if (st.empty() || st.top() == '(') {
						possible = false;
						break;
					}
					else {
						st.pop();
					}
				}
			}
		}
		if (possible && st.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}
