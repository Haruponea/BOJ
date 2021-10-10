#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	list<int> l;
	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}
	auto cursor = l.begin();
	cout << '<';
	while (!l.empty()) {
		for (int i = 0; i < k - 1; i++) {
			cursor++;
			if (cursor == l.end())
				cursor = l.begin();
		}

		cout << *cursor;
		cursor = l.erase(cursor);
		if (cursor == l.end())
			cursor = l.begin();
		if (!l.empty()) {
			cout << ", ";
		}
		else
			cout << '>';
	}
}
