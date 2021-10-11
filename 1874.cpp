#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, num = 1;
	cin >> n;
	stack<int> s;
	vector<int> target;
	vector<char> ans;
	for(int i =0;i<n;i++) {
		int k;
		cin >> k;
		target.push_back(k);
	}
	int idx = 0;
	while (idx < n) {
		if (s.empty() || s.top() < target[idx]) {
			ans.push_back('+');
			s.push(num++);
		}
		else if (s.top() == target[idx]) {
			s.pop();
			ans.push_back('-');
			idx++;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (char c : ans)
		cout << c << '\n';
}
