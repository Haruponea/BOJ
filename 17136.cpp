#include <iostream>
#include <algorithm>
using namespace std;

int paper[6] = { 0,5,5,5,5,5 };
int board[10][10];
int possible_max_paper[10][10];
int ans=30, target_cnt;
int find_max_type(int x, int y) {
    int val = 0;
    for (int k = 1; k <= 5; k++) {
        bool possible = true;
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                if (i >= 10 || j >= 10 || board[i][j] == 0) {
                    possible = false;
                }
            }
        }
        if (possible) val = k;
        else break;
    }
    return val;
}

bool check(int i, int j, int k) {
    for (int x = i; x < i + k; x++) {
        for (int y = j; y < j + k; y++) {
            if (board[x][y] == 0) return false;
        }
    }
    return true;
}

void func(int x, int y) {
    if (ans <= 25 - paper[1] - paper[2] - paper[3] - paper[4] - paper[5]) 
        return;
    if (target_cnt == 0) {
        ans = min(ans, 25 - paper[1] - paper[2] - paper[3] - paper[4] - paper[5]);
        return;
    }
    if (x == 10) return;
    if (board[x][y] == 1) {
        possible_max_paper[x][y] = find_max_type(x, y);
        for (int k = possible_max_paper[x][y]; k >= 1; k--) {
            if (paper[k] == 0) continue;
            for (int i = x; i < x + k; i++) {
                for (int j = y; j < y + k; j++) {
                    board[i][j] = 0;
                }
            }
            paper[k]--;
            target_cnt -= k * k;

            if (y + 1 == 10)
                func(x + 1, 0);
            else
                func(x,y+1);

            paper[k]++;
            target_cnt += k * k;
            for (int i = x; i < x + k; i++) {
                for (int j = y; j < y + k; j++) {
                    board[i][j] = 1;
                }
            }
        }
    }
    else {
        if (y + 1 == 10) {
            func(x + 1, 0);
        }
        else
            func(x, y + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10 ; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                target_cnt++;
        }
    }

    func(0, 0);
    ans = (ans == 30) ? -1 : ans;
    cout << ans;
}
