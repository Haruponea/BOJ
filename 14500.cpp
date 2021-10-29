#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int board[502][502];
int tetromino[5][4][4] = {
    {
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {1,0,0,0},
        {1,0,0,0},
        {1,1,0,0},
        {0,0,0,0}
    },
    {
        {1,0,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,0,0,0}
    },
    {
        {1,1,1,0},
        {0,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};
pair<int, int> rc[5] = { {1,4},{2,2},{3,2},{3,2},{2,3} };
int n, m, r, c, ans;
int curtet[4][4];
void symmetry() {
    int tmp[4][4];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][c-1-j] = curtet[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            curtet[i][j] = tmp[i][j];
        }
    }
}
void rotate() {
    int tmp[4][4];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            tmp[i][j] = curtet[r - 1 - j][i];
        }
    }
    swap(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            curtet[i][j] = tmp[i][j];
        }
    }
}

void check() {
    for (int k = 0; k < 4; k++) {
        for (int x = 0; x <= n - r; x++) {
            for (int y = 0; y <= m - c; y++) {
                int cnt = 0;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (curtet[i][j] == 1) {
                            cnt +=board[x+i][y+j];
                        }
                    }
                }
                ans = max(ans, cnt);
            }
        }
        rotate();
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    for (int i = 0; i < 5; i++) {
        r = rc[i].first; c = rc[i].second;
        for (int a = 0; a < r; a++)
            for (int b = 0; b < c; b++)
                curtet[a][b] = tetromino[i][a][b];
        check();
        symmetry();
        check();
    }
    cout << ans;
}
