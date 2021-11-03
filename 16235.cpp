#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int dead[12][12];
int ground[12][12];
deque<int> tree[12][12];
int A[12][12];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int n, m, k;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            ground[i][j] = 5;
            cin >> A[i][j];
        }

    for (int i = 0; i < m; i++) {
        int x, y, o;
        cin >> x >> y >> o;
        tree[x-1][y-1].push_back(o);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!tree[i][j].empty())
                sort(tree[i][j].begin(),tree[i][j].end());
    int year = 0;
    while (year < k) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!tree[i][j].empty()) {
                    for (auto itr = tree[i][j].begin(); itr != tree[i][j].end();) {
                        if (*itr > ground[i][j]) {
                            dead[i][j] += *itr / 2;
                            itr = tree[i][j].erase(itr);
                        }
                        else {
                            ground[i][j] -= *itr;
                            *itr += 1;
                            itr++;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!tree[i][j].empty()) {
                    for (auto itr = tree[i][j].begin(); itr != tree[i][j].end();itr++) {
                        if (*itr % 5 == 0) {
                            for (int dir = 0; dir < 8; dir++) {
                                int nx = i + dx[dir];
                                int ny = j + dy[dir];
                                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                                tree[nx][ny].push_front(1);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ground[i][j] += A[i][j] + dead[i][j];
                dead[i][j] = 0;
            }
        }
        year++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += tree[i][j].size();
        }
    }
    cout << cnt;
}
