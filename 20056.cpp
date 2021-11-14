#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct fireballinfo {
    int r;
    int c;
    int m;
    int s;
    int d;
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int n, M, k;
vector<fireballinfo> board[52][52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>> M >> k;
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({ r,c,m,s,d });
    }
    int move = 0;
    while (move < k) {
        vector<fireballinfo> tmp[52][52];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j].empty()) continue;
                for (int idx = 0; idx < board[i][j].size(); idx++) {
                    int dir = board[i][j][idx].d;
                    int nx = board[i][j][idx].r, ny = board[i][j][idx].c;
                    for (int moving = 0; moving < (board[i][j][idx].s % n); moving++) {
                        nx += dx[dir]; ny += dy[dir];
                        if (nx < 1) nx = n;
                        if (nx > n) nx = 1;
                        if (ny < 1) ny = n;
                        if (ny > n) ny = 1;
                    }
                    tmp[nx][ny].push_back({ nx,ny,board[i][j][idx].m,board[i][j][idx].s,dir });
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (tmp[i][j].size() >= 2) {
                    int msum = 0, ssum = 0, cnt = tmp[i][j].size();
                    int firstdir = tmp[i][j][0].d % 2;
                    bool isdireven = true;
                    for (int idx = tmp[i][j].size() - 1; idx >= 0; idx--) {
                        msum += tmp[i][j][idx].m;
                        ssum += tmp[i][j][idx].s;
                        if (tmp[i][j][idx].d % 2 != firstdir ) isdireven = false;
                        tmp[i][j].pop_back();
                    }
                    msum /= 5;
                    if (msum == 0) continue;
                    ssum /= cnt;
                    if (isdireven) {
                        tmp[i][j].push_back({ i,j,msum,ssum,0 });
                        tmp[i][j].push_back({ i,j,msum,ssum,2 });
                        tmp[i][j].push_back({ i,j,msum,ssum,4 });
                        tmp[i][j].push_back({ i,j,msum,ssum,6 });
                    }
                    else {
                        tmp[i][j].push_back({ i,j,msum,ssum,1 });
                        tmp[i][j].push_back({ i,j,msum,ssum,3 });
                        tmp[i][j].push_back({ i,j,msum,ssum,5 });
                        tmp[i][j].push_back({ i,j,msum,ssum,7 });
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                board[i][j] = tmp[i][j];
        move++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (board[i][j].empty()) continue;
            for (int idx=0;idx<board[i][j].size();idx++)
                ans += board[i][j][idx].m;
        }
    cout << ans;
}
