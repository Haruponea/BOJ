#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
int board[52][10];
int order[10];
bool isused[10];
void func(int level) {
    if (level == 9) {
        int i = 0, score = 0, playeridx=0;
        for (int i = 0; i < n; i++) {
            int base[4] = { 0,0,0,0 }; //0은 홈, 1은 1루, 2는 2루, 3은 3루
            int out = 0;
            while (true) {
                int run = board[i][order[playeridx]];
                if (run == 0) {
                    out++;
                }
                else {
                    base[0] = 1;
                    for (int j = 3; j >=0; j--) {
                        if (base[j] == 0) continue;
                        if (j + run >= 4) {
                            score++;
                            base[j] = 0;
                        }
                        else {
                            base[j] = 0;
                            base[j + run] = 1;
                        }
                    }
                }
                playeridx = (playeridx + 1 < 9) ? playeridx + 1 : 0;
                if (out >= 3) break;
            }
        }
        ans = max(ans, score);
    }
    else if (level == 3) {
        order[level] = 0;
        isused[0] = true;
        func(level + 1);
    }
    else {
        for (int i = 1; i < 9; i++) {
            if (isused[i] == true) continue;
            isused[i] = true;
            order[level] = i;
            func(level + 1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    func(0);
    cout << ans;
}
