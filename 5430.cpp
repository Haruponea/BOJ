#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		bool reverse = false;
		bool error = false;
		deque<int> dq;
		string f, nums;
		int n;
		cin >> f >> n >> nums;
		int cur = 0;
		for (char c : nums) {
			if ('0' <= c && c <= '9') {
				cur = cur * 10 + (int)(c - '0');
			}
			else if (c == ',') {
				dq.push_back(cur);
				cur = 0;
			}
			else if (cur != 0 && c == ']') {
				dq.push_back(cur);
			}
		}
		for (char order : f) {
			if (order == 'R') {
				reverse = 1 - reverse;
			}
			else if (order == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				if (reverse) {
					dq.pop_back();
				}
				else dq.pop_front();
			}
		}
		if (error) {
			cout << "error\n";
			continue;
		}
		else{
			cout << '[';
			if (reverse) {
				for (int i = dq.size()-1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0)
						cout << ',';
				}
			}
			else {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i + 1 != dq.size())
						cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}
