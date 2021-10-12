#include <iostream>
#include <algorithm>

using namespace std;

int N, s, e, i;
int q[2000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	while (N--) {
		string st;
		cin >> st;
		if (st == "push") {
			cin >> q[e++];
		}
		else if (st == "pop") {
			cout << (s == e ? -1 : q[s++]) << '\n';
		}
		else if (st == "size") {
			cout << e - s << '\n';
		}
		else if (st == "empty") {
			cout << (s == e) << '\n';
		}
		else if (st == "front") {
			cout << (s == e ? -1 : q[s]) << '\n';
		}
		else if (st == "back") {
			cout << (s == e ? -1 : q[e - 1]) << '\n';
		}
	}
}
