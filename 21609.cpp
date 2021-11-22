#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int board[23][23]; //-2 는 빈칸 -1은 검은색 0은 무지개 1~M 일반블록
int n, m, score;
int maxx, maxy;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool vis[23][23];

bool comp(tuple<int, int, int, int>a, tuple<int, int, int, int> b) {
    int acnt, arainbow, ax, ay, bcnt, brainbow, bx, by;
    tie(acnt, arainbow, ax, ay) = a;
    tie(bcnt, brainbow, bx, by) = b;
    if (acnt == bcnt) {
        if (arainbow == brainbow) {
            if (ax == bx) {
                return ay > by;
            }
            else return ax > bx;
        }
        else return arainbow > brainbow;
    }
    else return acnt > bcnt;
}

bool find_max_block() {
    bool exist = false;
    vector<tuple<int, int, int, int>> v;
    for (int i = 0; i < 23; i++) fill(vis[i], vis[i] + 23, false);
    for (int i = 0; i <n; i++) {
        for (int j = 0; j <n; j++) {
            if (board[i][j] <= 0) continue;
            if (vis[i][j] == true) continue;
            int curcolor = board[i][j];
            vector<pair<int, int>> rainbow;
            queue<pair<int, int>> q;
            int cnt = 0;
            q.push({ i,j });
            vis[i][j] = true;
            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                if (board[cur.first][cur.second] == 0) rainbow.push_back(cur);
                cnt++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny] == true) continue;
                    if (board[nx][ny] == 0 || board[nx][ny] == curcolor) {
                        q.push({ nx,ny });
                        vis[nx][ny] = true;
                    }
                }
            }
            if (cnt > 1) {
                v.push_back({ cnt,rainbow.size(),i,j });
                exist = true;
            }
            for (pair<int, int> point : rainbow)
                vis[point.first][point.second] = false;
        }
    }

    if (exist) {
        sort(v.begin(), v.end(), comp);
        maxx = get<2>(v[0]);
        maxy = get<3>(v[0]);
    }
    return exist;
}

void erase_max_block() {
    int cnt = 0, curcolor=board[maxx][maxy];
    for (int i = 0; i < 23; i++) fill(vis[i], vis[i] + 23, false);
    queue<pair<int, int>> q;
    q.push({ maxx,maxy });
    vis[maxx][maxy] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop(); cnt++;
        board[cur.first][cur.second] = -2;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] == true) continue;
            if (board[nx][ny] == 0 || board[nx][ny] == curcolor) {
                q.push({ nx,ny });
                vis[nx][ny] = true;
            }

        }
    }
    score += cnt * cnt;
}

void gravity() {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] < 0) continue;
            int nx = i + 1;
            while (true) {
                if (nx < n && board[nx][j] == -2) nx++;
                else break;
            }
            int tmp = board[i][j];
            board[i][j] = -2;
            board[nx-1][j] = tmp;
        }
    }
}

void rotate() {
    int tmp[22][22];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = board[j][n - 1 - i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

void solve() {
    while (true) {
        bool exist = find_max_block();
        if(!exist) break;
        erase_max_block();
        gravity();
        rotate();
        gravity();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    find_max_block();
    solve();
    cout << score;
}
