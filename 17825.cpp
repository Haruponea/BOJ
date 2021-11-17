#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans;
int p[4];
int dice[10];
bool is_full[35];
vector<int> board;

void ini_board() {
    board.push_back(0);
    for (int i = 1; i < 20; i++) board.push_back(2 * i);
    for (int i = 1; i <= 3; i++) board.push_back(10 + (3 * i));
    for (int i = 1; i <= 2; i++) board.push_back(20 + (2 * i));
    for (int i = 0; i < 3; i++) board.push_back(28 - i);
    for (int i = 1; i <= 4; i++) board.push_back(20 + (5 * i));
}

int get_next_idx(int curposition, int d) {
    if (0 <= curposition && curposition < 5) curposition += d;
    else if (curposition == 5) {
        if (d <= 3) curposition = 19 + d;
        else curposition = 24 + d;
    }
    else if (6 <= curposition && curposition < 10) curposition += d;
    else if (curposition == 10) {
        if (d <= 2) curposition = 22 + d;
        else curposition = 25 + d;
    }
    else if (11 <= curposition && curposition < 15) curposition += d;
    else if (curposition == 15) {
        curposition = 24 + d;
    }
    else if (16 <= curposition && curposition <= 19) {
        if (curposition + d == 20) curposition = 31;
        else if (curposition + d > 20) curposition = 32;
        else curposition = curposition + d;
    }
    else if (20 <= curposition && curposition <= 22) {
        if (curposition + d <= 22) curposition += d;
        else curposition = 27 + curposition + d - 22;
    }
    else if (23 <= curposition && curposition <= 24) {
        if (curposition + d <= 24) curposition += d;
        else curposition = 27 + curposition + d - 24;
    }
    else if (25 <= curposition && curposition <= 27) {
        curposition += d;
    }
    else if (28 <= curposition && curposition <= 31) {
        if (curposition + d > 31) curposition = 32;
        else curposition += d;
    }
    return curposition;
}

void func(int level,int score) {
    if (level == 10) {
        ans = max(ans, score);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (p[i] > 31) continue;
        int next = get_next_idx(p[i], dice[level]);
        int cur = p[i];
        if (next <= 31) {
            if (is_full[next]) continue;
            is_full[next] = true;
            score += board[next];
            p[i] = next;
            is_full[cur] = false;
            func(level + 1, score);
            is_full[next] = false;
            score -= board[next];
            is_full[cur] = true;
            p[i] = cur;
        }
        else {
            p[i] = next;
            is_full[cur] = false;
            func(level + 1, score);
            is_full[cur] = true;
            p[i] = cur;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ini_board();
    for (int i = 0; i < 10; i++) cin >> dice[i];
    func(0, 0);
    cout << ans;
}
