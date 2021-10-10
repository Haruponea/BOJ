#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		list<char> l;
		auto cursor = l.begin();
		for (char c : s) {
			if (c == '-') {
				if (cursor != l.begin()) {
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else if (c == '<') {
				if (cursor != l.begin()) {
					cursor--;
				}
			}
			else if (c == '>') {
				if (cursor != l.end()) {
					cursor++;
				}
			}
			else {
				l.insert(cursor, c);
			}
		}
		for (char c : l) 
			cout << c;
		cout << '\n';
	}
}
