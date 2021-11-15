#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m, k, ans=987654321;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[53][53];
int tmp[53][53];
int idx[6];
int used[6];
vector<tuple<int, int, int>> v;

void rotate() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int r, c, s;
        tie(r, c, s) = v[idx[i]];
        int sx = r - s, sy = c - s, ex = r + s, ey = c + s;
        while (sx != ex) {
            int save = tmp[sx][sy];
            for (int i = sx; i < ex; i++) {
                tmp[i][sy] = tmp[i + 1][sy];
            }
            for (int i = sy; i < ey; i++) {
                tmp[ex][i] = tmp[ex][i + 1];
            }
            for (int i = ex; i > sx; i--) {
                tmp[i][ey] = tmp[i - 1][ey];
            }
            for (int i = ey; i > sy; i--) {
                tmp[sx][i] = tmp[sx][i - 1];
            }
            tmp[sx][sy + 1] = save;
            sx++; sy++; ex--; ey--;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt += tmp[i][j];
        }
        ans = min(ans, cnt);
    }
}

void backtracking(int level) {
    if (level == k) {
        rotate();
        return;
    }
    for (int i = 0; i < k; i++) {
        if (used[i] == true) continue;
        used[i] = true;
        idx[level] = i;
        backtracking(level + 1);
        used[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> board[i][j];
    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({ r,c,s });
    }

    backtracking(0);
    cout << ans;
}
