#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define x first
#define y second

int board[12][12];
int n, ans, cnt;
bool vis1[20];
bool vis2[20];
void func(int level) {
	if (level == 2 * n - 1) {
		return;
	}
	if (level < n) {
		pair<int, int> st = { level,0 };
		bool possible = false;
		for (int i = 0; i < level + 1; st.first--, st.second++, i++) {
			if (board[st.first][st.second] == 1 && vis1[level]==false && vis2[st.first-st.second+n - 1] == false){
				vis1[level] = true;
				possible = true;
				vis2[st.first - st.second + n - 1] = true;
				cnt++;
				ans = max(ans, cnt);
				func(level + 1);
				vis1[level] = false;
				vis2[st.first - st.second + n - 1] = false;
				cnt--;
			}
		}
		if (!possible)
			func(level + 1);
	}
	else if (level >= n) {
		pair<int, int> st = { n - 1,level-n+1 };
		bool possible = false;
		for (int i = 0; i < 2*n - 1 - level; st.first--, st.second++, i++) {
			if (board[st.first][st.second] == 1 && vis1[level] == false && vis2[st.first - st.second + n - 1] == false) {
				vis1[level] = true;
				possible = true;
				vis2[st.first - st.second + n - 1] = true;
				cnt++;
				ans = max(ans, cnt);
				func(level + 1);
				vis1[level] = false;
				vis2[st.first - st.second + n - 1] = false;
				cnt--;
			}
		}
		if (!possible)
			func(level + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	func(0);
	cout << ans;
}
