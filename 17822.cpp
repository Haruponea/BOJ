#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int n, m, t, sum, numcnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
deque<int> board[52];

void rotate(int idx, int dir, int k) {
    if (dir == 0) {
        for (int i = idx; i <= n; i += idx) {
            for (int j = 0; j < k; j++) {
                board[i].push_front(board[i].back());
                board[i].pop_back();
            }
        }
    }
    else {
        for (int i = idx; i <= n; i += idx) {
            for (int j = 0; j < k; j++) {
                board[i].push_back(board[i].front());
                board[i].pop_front();
            }
        }
    }
}

void check() {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) continue;
            int cnt = 1, curnum=board[i][j];
            queue<pair<int, int>> q;
            q.push({ i,j });
            board[i][j] = 0; numcnt--; sum -= curnum;
            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (ny < 0) ny = m - 1;
                    else if (ny >= m) ny = 0;
                    if (nx<1 || nx>n) continue;
                    if (board[nx][ny] != curnum) continue;
                    board[nx][ny] = 0;
                    cnt++;
                    numcnt--; sum -= curnum;
                    q.push({ nx,ny });
                }
            }
            if (cnt == 1) {
                board[i][j] = curnum;
                numcnt++;
                sum += curnum;
            }
            else flag = true;
        }
    }
    if (!flag) {
        int sumtmp = sum;
        int numcnttmp = numcnt;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) continue;
                if (board[i][j]*numcnt < sum) {
                    board[i][j] += 1; sumtmp++;
                }
                else if (board[i][j]*numcnt > sum) {
                    board[i][j] -= 1;
                    sumtmp--;
                    if (board[i][j] == 0) numcnttmp--;
                }
            }
        }
        sum = sumtmp;
        numcnt = numcnttmp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int q;
            cin >> q;
            board[i].push_back(q);
            sum += q;
            numcnt++;
        }
    }

    while (t--) {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        check();
        if (sum == 0) break;
    }
    cout << sum;
}
