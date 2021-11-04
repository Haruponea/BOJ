#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int board[52][52];
bool vis[52][52];
int n, m, vlen,cnt, ans = 999999999;
vector<pair<int, int>> v;
vector<int> idx;
void func(int level, int start) {
    if (level == m) {
        for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
        queue<pair<int, int>> q;
        for (int i = 0; i < idx.size(); i++) {
            q.push({ v[idx[i]] });
            vis[v[idx[i]].first][v[idx[i]].second] = true;
        }
        int totalblank = cnt;
        int time=0;
        while (!q.empty()) {
            if (time > ans) break;
            if (totalblank == 0) {
                ans = min(ans, time);
                break;
            }
            int qsize = q.size();
            for (int i = 0; i < qsize;i++) {
                pair<int, int> cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (board[nx][ny] == 1 || vis[nx][ny] == true)continue;
                    q.push({ nx,ny });
                    vis[nx][ny] = true;
                    if (board[nx][ny] == 0) totalblank--;
                }
            }
            time++;
        }
        return;
    }
    for (int i = start + 1; i < vlen; i++) {
        idx.push_back(i);
        func(level + 1, i);
        idx.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                v.push_back({ i,j });
            }
            else if (board[i][j] == 0)
                cnt++;
        }
    }
    vlen = v.size();
    func(0, -1);
    if (ans == 999999999) ans = -1;
    cout << ans;
}
