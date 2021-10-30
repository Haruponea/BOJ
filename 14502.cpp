#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[10][10];
bool vis[10][10];
int n, m, ans;
vector<pair<int, int>> virus;
vector<pair<int, int>> cand;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back({ i,j });
            else if (board[i][j] == 0)
                cand.push_back({ i,j });
        }
    }
    vector<int> brute(cand.size(), 1);
    fill(brute.begin(), brute.end()-3, 0);
    do {
        for (int i = 0; i < 10; i++) fill(vis[i], vis[i] + 10, false);
        vector<pair<int, int>> change;
        for (int i = 0; i < cand.size(); i++) {
            if (brute[i] == 1) {
                board[cand[i].first][cand[i].second] = 1;
                change.push_back({ cand[i].first,cand[i].second });
            }
        }
        queue<pair<int, int>> q;
        for (auto a : virus) {
            q.push(a);
            vis[a.first][a.second] = true;
        }
        int cnt = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop(); cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] == 1 || vis[nx][ny] == true) continue;
                vis[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
        ans = max(ans, (int)(cand.size() + virus.size() - 3 - cnt));
        for (auto a : change)
            board[a.first][a.second] = 0;
    } while (next_permutation(brute.begin(), brute.begin() + cand.size()));
    cout << ans;
}
