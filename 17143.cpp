#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int R, C, M, r, c, s, d, z, ans;

vector <tuple<int, int, int, int, int>> shark[102][102];//{r,c,s,d,z}

int change_dir(int dir) {
    if (dir == 0) return 1;
    else if (dir == 1) return 0;
    else if (dir == 2) return 3;
    else return 2;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> M;
    if (M == 0) {
        cout << 0;
        return 0;
    }
    for(int i =0; i<M; i++) {
        cin >> r >> c >> s >> d >> z;
        if (d <= 2) s %= 2 * (R - 1);
        else s %= 2 * (C - 1);
        shark[r - 1][c - 1].push_back({ r - 1, c - 1, s, d - 1, z });
    }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (!shark[j][i].empty()) {
                ans += get<4>(shark[j][i].front());
                shark[j][i].pop_back();
                break;
            }
        }
        vector <tuple<int, int, int, int, int>> nextshark[102][102];
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                if (shark[x][y].empty()) continue;
                tie(r, c, s, d, z) = shark[x][y].front(); shark[x][y].pop_back();
                int t = 0, nr, nc;
                while (t < s) {
                    nr = r + dx[d];
                    nc = c + dy[d];
                    if (nc < 0 || nr < 0 || nr >= R || nc >= C) {
                        d = change_dir(d);
                        nr = r + dx[d];
                        nc = c + dy[d];
                    }
                    r = nr; c = nc;
                    t++;
                }
                if (nextshark[r][c].empty()) {
                    nextshark[r][c].push_back({ r,c,s,d,z });
                }
                else {
                    if (z > get<4>(nextshark[r][c].front())) {
                        nextshark[r][c].pop_back();
                        nextshark[r][c].push_back({ r,c,s,d,z });
                    }
                }
            }
        }
        swap(shark, nextshark);
    }
    cout << ans;
}
