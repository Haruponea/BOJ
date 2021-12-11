#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[502][502];
int arr[502][502];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    else if (x == n - 1 && y == m - 1) {
        dp[x][y] = 1;
        return dp[x][y];
    }
    else {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] < arr[x][y]) {
                dp[x][y] += dfs(nx,ny);
            }
        }
        return dp[x][y];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 502; i++) fill(dp[i], dp[i] + 502, -1);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);
    cout << dp[0][0];
}
