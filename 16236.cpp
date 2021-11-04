#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int n, sharkx, sharky, sharksize = 2, sharkeat,t;
int board[22][22];
int vis[22][22];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sharkx = i, sharky = j;
                board[i][j] = 0;
            }
        }
    }

    while (true) {
        for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, -1);
        queue<tuple<int, int, int>> q;
        vector<pair<int, int>> v;
        int mindist = 500;
        q.push({ 0,sharkx,sharky });
        while (!q.empty()) {
            int curdist, curx, cury;
            tie(curdist, curx, cury) = q.front(); q.pop();
            if (curdist >= mindist) continue;
            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (board[nx][ny] > sharksize || vis[nx][ny] != -1) continue;
                if (board[nx][ny] != 0 && board[nx][ny] < sharksize) {
                    v.push_back({ nx,ny });
                    mindist = min(mindist, curdist + 1);
                }
                q.push({ curdist + 1,nx,ny });
                vis[nx][ny] = true;
            }
        }
        if (v.empty()) {
            cout << t;
            break;
        }
        else {
            sort(v.begin(), v.end(),compare);
            board[v[0].first][v[0].second] = 0;
            t += mindist;
            sharkx = v[0].first; sharky = v[0].second;
            sharkeat++;
            if (sharkeat == sharksize) {
                sharkeat = 0;
                sharksize++;
            }
        }
    }
}
