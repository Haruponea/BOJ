#include <iostream>
#include <algorithm>
using namespace std;

int human[23][23];
int area[23][23];
int cnt[5];
int n, total_human, ans=99999999;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> human[i][j];
            total_human += human[i][j];
        }
    }
    for (int d1 = 1; d1 <= n - 2; d1++) {
        for (int d2 = 1; d2 <= n - d1 - 1; d2++) {
            for (int x = 1; x <= n - d1 - d2; x++) {
                for (int y = 1 + d1; y <= n - d2; y++) {
                    fill(cnt, cnt + 5, 0);
                    for (int i = 0; i < 23; i++) fill(area[i], area[i] + 23, 0);
                    for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= n; j++) {
                            if (1 <= i && i < x + d1 && 1 <= j && j <= y && i + j < x + y) {
                                area[i][j] = 1;
                                cnt[1] += human[i][j];
                            }
                            else if (1 <= i && i <= x + d2 && y < j && j <= n && i - j < x - y) {
                                area[i][j] = 2;
                                cnt[2] += human[i][j];
                            }
                            else if (x+d1<=i && i<=n && 1<=j && j<y-d1+d2 &&i - j > x + d1 - y + d1) {
                                area[i][j] = 3;
                                cnt[3] += human[i][j];
                            }
                            else if(x+d2<i && i<=n && y-d1+d2<=j && j<=n && i + j > x + d2 + y + d2) {
                                area[i][j] = 4;
                                cnt[4] += human[i][j];
                            }
                        }
                    }
                    cnt[0] = total_human - (cnt[1] + cnt[2] + cnt[3] + cnt[4]);
                    sort(cnt, cnt + 5);
                    ans = min(ans, cnt[4] - cnt[0]);
                }
            }
        }
    }
    cout << ans;
}
