#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
vector<pair<int, int>> egg;
void func(int level) {
	if (level == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (egg[i].first <= 0) cnt++;
		}
		ans = (ans > cnt) ? ans : cnt;
		return;
	}

	if (egg[level].first <= 0) {
		func(level + 1);
	}
	else {
		bool possible = false;
		for (int i = 0; i < n; i++) {
			if (i == level || egg[i].first <= 0) continue;
			possible = true;
			egg[i].first -= egg[level].second;
			egg[level].first -= egg[i].second;
			func(level + 1);
			egg[i].first += egg[level].second;
			egg[level].first += egg[i].second;
		}
		if (!possible) func(level + 1); //하나를 제외하고 다 깨졌을때
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		egg.push_back({ a,b });
	}
	func(0);
	cout << ans;
}
