#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n = 1, m = 1, ans = 9999999999;
int dist[13][13] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int vis[22][22];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    while (n != 0 && m != 0) {
        vector <int> board[22];
        vector<pair<int, int>> dust;
        dust.push_back({ 0,0 });
        int label = 1;
        for (int i = 0; i < 13; i++) fill(dist[i], dist[i] + 13, -1);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '*') {
                    dust.push_back({ i,j });
                    board[i].push_back(label++);
                }
                else if (s[j] == '.') {
                    board[i].push_back(0);
                }
                else if (s[j] == 'x') {
                    board[i].push_back(-1);
                }
                else if (s[j] == 'o') {
                    board[i].push_back(0);
                    dust[0].first = i; dust[0].second = j;
                }
            }
        }
        for (int cnt = 0; cnt < dust.size(); cnt++) {
            for (int i = 0; i < 22; i++) fill(vis[i], vis[i] + 22, -1);
            queue<pair<int, int>> q;
            q.push(dust[cnt]);
            vis[dust[cnt].first][dust[cnt].second] = 0;
            int curlabel = board[dust[cnt].first][dust[cnt].second];
            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (board[nx][ny] == -1 || vis[nx][ny] != -1) continue;
                    q.push({ nx,ny });
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    if (1 <= board[nx][ny]) {
                        int nextlabel = board[nx][ny];
                        dist[curlabel][nextlabel] = vis[nx][ny];
                        dist[nextlabel][curlabel] = vis[nx][ny];
                    }
                }
            }
        }
        vector<int> brute;
        for (int i = 0; i < dust.size(); i++) brute.push_back(i);
        do {
            int distance = 0;
            bool possible = true;
            for (int i = 1; i < brute.size(); i++) {
                if (dist[brute[i - 1]][brute[i]] == -1) {
                    possible = false;
                    break;
                }
                else
                    distance += dist[brute[i - 1]][brute[i]];
            }
            if (possible == false) ans = -1;
            else ans = min(ans, distance);
        } while (next_permutation(brute.begin() + 1, brute.end()));
        cout << ans <<'\n';
        ans = 9999999999;
        cin >> m >> n;
    }
}
