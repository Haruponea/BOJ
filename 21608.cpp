#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int board[22][22];
vector<int> favorite[402];
vector<int> order;

bool compare(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) == get<1>(b)) {
            if (get<2>(a) == get<2>(b)) {
                if (get<3>(a) == get<3>(b))
                    return false;
                else return get<3>(a) < get<3>(b);
            }
            else return get<2>(a) < get<2>(b);
        }
        else return get<1>(a) > get<1>(b);
    }
    else return get<0>(a) > get<0>(b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int student, a;
        cin >> student;
        order.push_back(student);
        for (int j = 0; j < 4; j++) {
            cin >> a;
            favorite[student].push_back(a);
        }
    }

    for (int i = 0; i < n * n; i++) {
        int curstudent = order[i];
        vector<tuple<int, int, int, int>> place;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] != 0) continue;
                int blank = 0; int favoritecnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (board[nx][ny] == 0) blank++;
                    else {
                        for (int idx = 0; idx < 4; idx++) {
                            if (board[nx][ny] == favorite[curstudent][idx]) {
                                favoritecnt++;
                                break;
                            }
                        }
                    }
                    place.push_back({ favoritecnt,blank,x,y });
                }
            }
        }
        sort(place.begin(), place.end(), compare);
        board[get<2>(place[0])][get<3>(place[0])] = curstudent;
    }
    int score = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int favoritecnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                for (int idx = 0; idx < 4; idx++) {
                    if (board[nx][ny] == favorite[board[x][y]][idx])
                         favoritecnt++;
                }
            }
            if (favoritecnt == 1) score += 1;
            else if (favoritecnt == 2) score += 10;
            else if (favoritecnt == 3) score += 100;
            else if (favoritecnt == 4) score += 1000;
        }
    }
    cout << score;
}
