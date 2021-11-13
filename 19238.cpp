#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, fuel, taxix, taxiy, success;
int board[22][22];
bool done[402];
int dist[402][402];
vector<tuple<int, int, int, int>> v[402];//v[i](dist,x,y,num)
int vis[22][22];
vector<pair<int, int>> start;
vector<int> destination[22][22];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> fuel;
    for (int i = 0; i < 402; i++) fill(dist[i], dist[i] + 402, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    start.push_back({ -1, -1 });
    cin >> taxix >> taxiy;
    for (int i = 1; i <= m; i++) {
        int startx, starty, destx, desty;
        cin >> startx >> starty >> destx >> desty;
        destination[destx][desty].push_back(i);
        start.push_back({ startx,starty });
    }
    for (int idx = 1; idx <= m; idx++) {
        for (int i = 0; i < 22; i++) fill(vis[i], vis[i] + 22, -1);
        queue <pair<int, int>> q;
        int startx = start[idx].first, starty = start[idx].second;
        q.push({ startx,starty });
        vis[startx][starty] = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            if (cur.first == taxix && cur.second == taxiy) {
                v[0].push_back({ vis[cur.first][cur.second],startx,starty,idx });
                dist[idx][0] = vis[cur.first][cur.second];
                dist[0][idx] = vis[cur.first][cur.second];
            }
            if (destination[cur.first][cur.second].size() != 0) {
                for (int i = 0; i < destination[cur.first][cur.second].size(); i++) {
                    v[destination[cur.first][cur.second][i]].push_back({ vis[cur.first][cur.second],startx,starty,idx });
                    dist[idx][destination[cur.first][cur.second][i]] = vis[cur.first][cur.second];
                }
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx<1 || nx>n || ny<1 || ny>n) continue;
                if (board[nx][ny] == 1 || vis[nx][ny] != -1) continue;
                q.push({ nx,ny });
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }
    }
    for (int i = 0; i <= m; i++)
        sort(v[i].begin(), v[i].end());
    int curdest = 0;
    while (success<m) {
        int target_dist = -1, targetx = -1, targety = -1, target = -1;
        for (auto t : v[curdest]) {
            if (done[get<3>(t)] == true) continue;
            else {
                tie(target_dist, targetx,targety,target) = t;
                break;
            }
        }
        if (target_dist == -1) break;
        fuel -= target_dist;
        if (fuel <= 0) break;
        if (dist[target][target] == -1) break;
        fuel -= dist[target][target];
        if (fuel < 0) break;
        fuel += dist[target][target] * 2;
        curdest = target;
        success += 1;
        done[target] = true;
    }
    if (success == m) cout << fuel;
    else cout << -1;
}
