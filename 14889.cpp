#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, mn=10000000003;
int arr[22][22];
vector<int> team1;
vector<int> team2;
void func(int level) {
    if (level == n) {
        int teampower[2] = {};
        for (int i : team1) {
            for (int j : team1) {
                teampower[0] += arr[i][j];
            }
        }
        for (int i : team2) {
            for (int j : team2) {
                teampower[1] += arr[i][j];
            }
        }
        mn = min(mn, abs(teampower[0] - teampower[1]));
        return;
    }

    if (team1.size() < n / 2) {
        team1.push_back(level);
        func(level + 1);
        team1.pop_back();
    }
    if (team2.size() < n / 2) {
        team2.push_back(level);
        func(level + 1);
        team2.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    func(0);
    cout << mn;
}
