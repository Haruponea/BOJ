#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int board[102][102];
bool bodycheck[102][102];
deque<pair<int, int>> body;//front is tail, back is head
deque<pair<int, char>> order;
int n, k, l, x, curdir;
char c;
bool move() {
    pair<int, int> curhead = body.back();
    int nx = curhead.first + dx[curdir];
    int ny = curhead.second + dy[curdir];
    if (nx<1 || ny<1 || nx>n || ny>n || bodycheck[nx][ny] == true)
        return false;

    if (board[nx][ny] == 1) {
        bodycheck[nx][ny] = true;
        board[nx][ny] = 0;
        body.push_back({ nx,ny });
    }
    else if (board[nx][ny] == 0) {
        bodycheck[nx][ny] = true;
        body.push_back({ nx,ny });
        pair<int, int> tail = body.front();
        bodycheck[tail.first][tail.second] = false;
        body.pop_front();
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    cin >> l;
    while (l--) {
        int a;
        char b;
        cin >> a >> b;
        order.push_back({ a,b });
    }
    body.push_back({ 1,1 });
    bodycheck[1][1] = true;
    curdir = 3;
    int ans = 1;
    while (move()) {
        if (!order.empty() && ans == order.front().first) {
            if (order.front().second == 'L') {
                curdir = (curdir + 1) % 4;
            }
            else curdir = (curdir + 3) % 4;
            order.pop_front();
        }
        ans++;
    }
    cout << ans;
}
