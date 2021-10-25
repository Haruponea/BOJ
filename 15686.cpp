#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int n, m;
int board[52][52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2)
                chicken.push_back({ i,j });
            else if (board[i][j] == 1)
                house.push_back({ i,j });
        }
    }
    vector<int>brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
    int mn = 300000;
    do {
        int dist = 0;
        for (int i = 0; i < house.size(); i++) {
            int tmp = 300000;
            for (int j = 0; j < chicken.size(); j++) {
                if (brute[j] == 0)continue;
                tmp = min(tmp, abs(house[i].X - chicken[j].X) + abs(house[i].Y - chicken[j].Y));
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));
    cout << mn;
}
