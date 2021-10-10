#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<char> li;
	string s;
	cin >> s;
	for (char c : s)
		li.push_back(c);
	list<char>::iterator it = li.end();
	int n;
	cin >> n;
	while (n--) {
		char o;
		cin >> o;
		if (o == 'L') {
			if (it != li.begin())
				it--;
		}
		else if (o == 'D') {
			if (it != li.end())
				it++;
		}
		else if (o == 'B') {
			if (it != li.begin()) {
				it--;
				it=li.erase(it);
			}
		}
		else {
			char ch;
			cin >> ch;
			li.insert(it, ch);
		}
	}
	for (char c : li)
		cout << c;
}
