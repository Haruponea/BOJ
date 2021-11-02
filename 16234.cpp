#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, L, R, ans;
int board[52][52];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool vis[52][52];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        vector<vector<pair<int, int>>> v;
        bool possible = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == true) continue;
                bool isuni = false;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    int pd = abs(board[i][j] - board[nx][ny]);
                    if (pd >= L && pd <= R) {
                        possible = true;
                        isuni = true;
                        break;
                    }
                }
                if (isuni) {
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> vv;
                    vis[i][j] = true;
                    q.push({ i,j });
                    vv.push_back({ i,j });
                    while (!q.empty()) {
                        pair<int, int> cur = q.front(); q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            if (vis[nx][ny] == true)continue;
                            int pd = abs(board[cur.first][cur.second] - board[nx][ny]);
                            if (pd >= L && pd <= R) {
                                vis[nx][ny] = true;
                                q.push({ nx,ny });
                                vv.push_back({ nx,ny });
                            }
                        }
                    }
                    v.push_back(vv);
                }
            }
        }
        if (possible == false) break;
        for (vector<pair<int, int>> area : v) {
            int sum = 0;
            for (pair<int, int> p : area) {
                sum += board[p.first][p.second];
            }
            sum /= area.size();
            for (pair<int, int> p : area) {
                board[p.first][p.second] = sum;
            }
        }
        for (int i = 0; i < 52; i++) fill(vis[i], vis[i] + 52, false);
        ans++;
    }
    cout << ans;
}
