#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int board[102][102];
int n, k, col_start, raw_start, col_end;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int tmp[102][102];
void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void put_one_fish() {
    vector<pair<int, int>> v;
    int min = 100000;
    for (int i = 0; i < n; i++) {
        if (board[n - 1][i] < min) {
            min = board[n - 1][i];
            v.clear();
            v.push_back({ n - 1,i });
        }
        else if (board[n - 1][i] == min)
            v.push_back({ n - 1,i });
    }
    for (pair<int, int> p : v) {
        board[p.first][p.second]++;
    }
}

bool first_leviation() {
    if (n - 1 - col_end < n - raw_start) return false;
    int stack_x = n - 1, stack_y;
    for (int i = col_end; i >= col_start; i--) {
        stack_x--; stack_y = col_end + 1;
        for (int j = n - 1; j >= raw_start; j--) {
            board[stack_x][stack_y++] = board[j][i];
            board[j][i] = 0;
        }
    }
    col_start = col_end + 1;
    col_end += n - raw_start;
    raw_start = stack_x;
    return true;
}

void adjust_fish_num() {
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    for (int i = raw_start; i < n; i++) {
        for (int j = col_start; j < n; j++) {
            if (board[i][j] == 0) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx >= n || ny >= n || nx < raw_start || ny < col_start) continue;
                if (board[nx][ny] >= board[i][j] || board[nx][ny] == 0) continue;
                int d = (board[i][j] - board[nx][ny]) / 5;
                if (d > 0) {
                    tmp[nx][ny] += d;
                    tmp[i][j] -= d;
                }
            }
        }
    }
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

void bottom_fish() {
    int tmp2[102] = { 0, };
    int idx1 = 0, idx2;
    for (int j = col_start; j < n; j++) {
        idx2 = n - 1;
        while (board[idx2][j] != 0) {
            tmp2[idx1++] = board[idx2][j];
            board[idx2--][j] = 0;
        }
    }
    for (int i = 0; i < 102; i++) {
        board[n - 1][i] = tmp2[i];
    }
    col_start = 0;
    col_end = 0;
    raw_start = 0;
}

void second_leviation() {
    for (int i = 0; i < n / 2; i++) {
        board[n - 2][n - 1 - i] = board[n - 1][i];
        board[n - 1][i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n / 4; j++) {
            board[n - 3 - i][(n / 2) + (n / 4) + j] = board[n - 2 + i][(n / 2) + (n / 4) - 1 - j];
            board[n - 2 + i][(n / 2) + (n / 4) - 1 - j] = 0;
        }
    }
    col_start = (n / 2);
    col_end = n - 1;
    raw_start = n - 4;
}

void solve() {
    put_one_fish();
    board[n - 2][1] = board[n - 1][0];
    board[n - 1][0] = 0;
    raw_start= n - 2; col_start = 1; col_end=1;
    while (first_leviation());
    adjust_fish_num();
    bottom_fish();
    second_leviation();
    adjust_fish_num();
    bottom_fish();
}

bool check() {
    int min = *min_element(board[n - 1], board[n - 1] + n);
    int max = *max_element(board[n - 1], board[n - 1] + n);
    if (max - min <= k) return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    raw_start = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> board[n - 1][i];
    }
    int t = 0;
    while (!check()) {
        solve();
        t++;
    }
    cout << t;
}
