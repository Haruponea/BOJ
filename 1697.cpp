#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int board[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	board[n] = 1;
	while (board[m] == 0) {
		int cur = q.front(); q.pop();
		for (int nxt : {cur + 1, cur - 1, cur * 2}) {
			if (nxt < 0 || nxt>100000) continue;
			if (board[nxt] != 0) continue;
			board[nxt] = board[cur] + 1;
			q.push(nxt);
		}
	}
	cout << board[m]-1;
}
