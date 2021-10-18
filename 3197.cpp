#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#define x first
#define y second
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

char board[1502][1502];
bool vis[1502][1502];
queue<pair<int, int>> swan;
queue<pair<int, int>> next_swan;
queue<pair<int, int>> water;
queue<pair<int, int>> next_water;
pair<int, int> swan_point;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'L')
				swan_point = { i,j };
			if (board[i][j] != 'X')
				water.push({ i,j });
		}
	}
	swan.push(swan_point);
	vis[swan_point.x][swan_point.y] = 1;
	board[swan_point.x][swan_point.y] = '.';
	int day = 0;
	bool possible = false;
	while (!possible) {
		while (!swan.empty()) {
			pair<int, int> cur = swan.front(); swan.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == 'L') {
					vis[nx][ny] = true;
					possible = true;
					break;
				}
				else if (board[nx][ny] == '.' && vis[nx][ny] == 0) {
					swan.push({ nx,ny });
					vis[nx][ny] = 1;
				}
				else if (board[nx][ny] == 'X' && vis[nx][ny] == 0) {
					next_swan.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
		if (possible) {
			cout << day;
			break;
		}
		day++;
		while (!water.empty()) {
			pair<int, int> cur = water.front(); water.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == 'X') {
					board[nx][ny] = '.';
					next_water.push({ nx,ny });
				}
			}
		}
		swap(swan, next_swan);
		swap(water, next_water);
	}
}
