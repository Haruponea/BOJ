#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[102][102];
int cnt[102];
int x, y, k, r = 3, c = 3, ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    x--; y--;

    while (true) {
        if (ans > 100) { cout << -1; break; }
        else if (board[x][y] == k) { cout << ans; break; }
        ans++;
        if (r >= c) {
            vector<int> l;
            for (int i = 0; i < r; i++) {
                vector<pair<int, int>> v;
                fill(cnt, ::cnt + 102, 0);
                for (int j = 0; j < c; j++) {
                    cnt[board[i][j]]++;
                    board[i][j] = 0;
                }
                for (int j = 1; j <= 100; j++) {
                    if (cnt[j] == 0) continue;
                    v.push_back({ cnt[j],j });
                }
                sort(v.begin(), v.end());
                int len = 0;
                for (int j = 0; j < v.size(); j++) {
                    board[i][len++] = v[j].second;
                    board[i][len++] = v[j].first;
                }
                l.push_back(len);
            }
            sort(l.begin(), l.end());
            c = l.back();
            if (c > 100) c = 100;
        }
        else {
            vector<int> l;
            for (int i = 0; i < c; i++) {
                vector<pair<int, int>> v;
                fill(cnt, ::cnt + 102, 0);
                for (int j = 0; j < r; j++) {
                    cnt[board[j][i]]++;
                    board[j][i] = 0;
                }
                for (int j = 1; j <= 100; j++) {
                    if (cnt[j] == 0) continue;
                    v.push_back({ cnt[j],j });
                }
                sort(v.begin(), v.end());
                int len = 0;
                for (int j = 0; j < v.size(); j++) {
                    board[len++][i] = v[j].second;
                    board[len++][i] = v[j].first;
                }
                l.push_back(len);
            }
            sort(l.begin(), l.end());
            r = l.back();
            if (r > 100) r = 100;
        }
    }
}
