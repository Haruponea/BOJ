#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dice[6] = { 1,6,4,3,5,2 };//상하좌우앞뒤
int board[23][23];
bool vis[23][23];
int n, m, ans, k, dice_dir = 0, dice_x = 1, dice_y = 1;

int reverse_dir() {
    if (dice_dir == 0) return 2;
    else if (dice_dir == 2) return 0;
    else if (dice_dir == 1) return 3;
    else return 1;
}

void get_score() {
    for (int i = 0; i < 23; i++) fill(vis[i], vis[i] + 23, false);
    queue<pair<int, int>> q;
    int cnt = 0;
    int curnum = board[dice_x][dice_y];
    q.push({ dice_x,dice_y });
    vis[dice_x][dice_y] = true;
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop(); cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx<1 || ny<1 || nx>n || ny>m) continue;
            if (board[nx][ny] != curnum || vis[nx][ny] == true) continue;
            vis[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    ans += cnt * curnum;
}

void change_dir() {
    int curnum = board[dice_x][dice_y];
    if (curnum < dice[1]) {
        dice_dir = (dice_dir + 1) % 4;
    }
    else if(curnum>dice[1]){
        dice_dir -= 1;
        if (dice_dir == -1) dice_dir = 3;
    }
}

void move_dice() {
    int nx = dice_x + dx[dice_dir];
    int ny = dice_y + dy[dice_dir];
    if (nx < 1 || ny < 1 || nx > n || ny > m) {
        dice_dir=reverse_dir();
        nx = dice_x + dx[dice_dir];
        ny = dice_y + dy[dice_dir];
    }

    if (dice_dir == 0) {
        int tmp1 = dice[2], tmp2 = dice[3];
        dice[2] = dice[1], dice[3] = dice[0];
        dice[0] = tmp1, dice[1] = tmp2;
    }
    else if (dice_dir == 1) {
        int tmp1 = dice[4], tmp2 = dice[5];
        dice[4] = dice[0], dice[5] = dice[1];
        dice[1] = tmp1, dice[0] = tmp2;
    }
    else if (dice_dir == 2) {
        int tmp1 = dice[2], tmp2 = dice[3];
        dice[2] = dice[0], dice[3] = dice[1];
        dice[1] = tmp1, dice[0] = tmp2;
    }
    else {
        int tmp1 = dice[4], tmp2 = dice[5];
        dice[4] = dice[1], dice[5] = dice[0];
        dice[0] = tmp1, dice[1] = tmp2;
    }
    dice_x = nx;
    dice_y = ny;
    get_score();
    change_dir();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    while (k--) {
        move_dice();
    }
    cout << ans;
}
