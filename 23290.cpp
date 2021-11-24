#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int sharkx, sharky;
int m, s;
int fish_dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int fish_dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int shark_dx[5] = { 0,-1,0,1,0 };
int shark_dy[5] = { 0,0,-1,0,1 };
vector<int> board[6][6];
vector<int> tmp[6][6];
vector<pair<int, tuple<int,int,int>>> shark_path;
int smell[6][6];
int arr[3];
vector<int> board_tmp[6][6];

int next_fish_dir(int curdir) {
    int next_dir = curdir - 1;
    if (next_dir == 0) next_dir = 8;
    return next_dir;
}

void copy_fish() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            board_tmp[i][j] = board[i][j];
        }
    }
}

void move_fish() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tmp[i][j].clear();
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (board[i][j].empty()) continue;
            for (int idx = 0; idx < board[i][j].size(); idx++) {
                int curdir = board[i][j][idx];
                bool possible = false;
                for (int k = 0; k < 8; k++) {
                    int nx = i + fish_dx[curdir];
                    int ny = j + fish_dy[curdir];
                    if ((nx < 1 || ny < 1 || nx>4 || ny>4) || (nx == sharkx && ny == sharky) || smell[nx][ny] != 0) {
                        curdir = next_fish_dir(curdir);
                        continue;
                    }
                    possible = true;
                    break;
                }
                if (possible) {
                    tmp[i + fish_dx[curdir]][j + fish_dy[curdir]].push_back(curdir);
                }
                else {
                    tmp[i][j].push_back(curdir);
                }
            }
        }
    }
    swap(tmp,board);
}
bool comp(pair<int, tuple<int,int,int>> a, pair<int, tuple<int,int,int>> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else return a.first > b.first;
}

void backtracking(int level, int cnt, int x, int y) {
    if (level == 3) {
        shark_path.push_back(make_pair( cnt,make_tuple(arr[0],arr[1],arr[2])));
        return;
    }
    for (int dir = 1; dir < 5; dir++) {
        arr[level] = dir;
        int nx = x + shark_dx[dir];
        int ny = y + shark_dy[dir];
        if (nx < 1 || ny < 1 || nx>4 || ny>4) continue;
        vector<int> fish_tmp = board[nx][ny];
        board[nx][ny].clear();
        backtracking(level + 1, cnt + fish_tmp.size(), nx, ny);
        board[nx][ny] = fish_tmp;
    }
}

void move_shark() {
    shark_path.clear();
    backtracking(0, 0, sharkx, sharky);
    int dir[3];
    sort(shark_path.begin(), shark_path.end(), comp);
    tie(dir[0], dir[1], dir[2]) = shark_path[0].second;
    int nx = sharkx, ny = sharky;
    for (int d : dir) {
        nx += shark_dx[d], ny += shark_dy[d];
        if (!board[nx][ny].empty()) {
            smell[nx][ny] = 3;
            board[nx][ny].clear();
        }
    }
    sharkx = nx; sharky = ny;
}

void update_smell() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (smell[i][j] == 0) continue;
            smell[i][j]--;
        }
    }
}

void complete_copy_fish() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for(int d:board_tmp[i][j])
                board[i][j].push_back(d);
        }
    }
}

void solve() {
    copy_fish();
    move_fish();
    move_shark();
    update_smell();
    complete_copy_fish();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> s;
    for (int i = 0; i < m; i++) {
        int fx, fy, d;
        cin >> fx >> fy >> d;
        board[fx][fy].push_back({ d });
    }
    cin >> sharkx >> sharky;
    while(s--)
        solve();
    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            sum += board[i][j].size();
        }
    }
    cout << sum;
}
