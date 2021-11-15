#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m, d, ans;
int board[18][18];
int distance(int a, int b, int x, int y) {
    return abs(a - x) + abs(b - y);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    vector<pair<int,int>> v;
    for (int j = 1; j <= m; j++) {
        v.push_back({ n + 1,j });
    }
    vector<int> brute(m, 0);
    fill(brute.begin() + m - 3, brute.end(), 1);
    do {
        vector<pair<int, int>> archer;
        int tmp[18][18];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                tmp[i][j] = board[i][j];

        for (int i = 0; i < m; i++) {
            if (brute[i] == 1)
                archer.push_back({ v[i] });
        }
        int cnt = 0;
        while (true){
            vector<tuple<int, int, int>> target[3];
            for (int a = 0; a < 3; a++) {
                pair<int, int> cur = archer[a];
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (tmp[i][j] == 1) {
                            if(distance(i, j, cur.first, cur.second)<=d)
                            target[a].push_back({ distance(i,j,cur.first,cur.second),j,i });
                        }
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                if (target[i].empty()) continue;
                else {
                    sort(target[i].begin(), target[i].end());
                    int dist, ty, tx;
                    tie(dist, ty, tx) = target[i][0];
                    if (tmp[tx][ty] == 1) cnt++;
                    tmp[tx][ty] = 0;
                }
            }

            bool isenermy = false;
            for (int i = n; i > 0; i--) {
                for (int j = 1; j <= m; j++) {
                    if (tmp[i][j] == 0) continue;
                    isenermy = true;
                    tmp[i][j] = 0;
                    if (i + 1 == n + 1) continue;
                    tmp[i + 1][j] = 1;
                }
            }
            if (!isenermy) {
                ans = max(ans, cnt);
                break;
            }
        }
    } while (next_permutation(brute.begin(), brute.end()));
    cout << ans;
}
