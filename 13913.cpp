#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#define x first
#define y second
using namespace std;

pair<int, int> board[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	queue<int> q;
	board[n] = { 1, n };
	q.push(n);
	
	while (board[k].first == 0) {
		int cur = q.front(); q.pop();
		for (int nx : {cur - 1, cur + 1, cur * 2}) {
			if (nx < 0 || nx >100000) continue;
			if (board[nx].first != 0) continue;
			q.push(nx);
			board[nx] = { board[cur].first + 1, cur };
		}
	}
	cout << board[k].first - 1 << '\n';
	stack<int> s;
	s.push(k);
	while (s.top() != n) {
		s.push(board[s.top()].second);
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}
