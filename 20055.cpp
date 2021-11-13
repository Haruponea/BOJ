#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> belt;
deque<int> robot;
int n, k, cnt, level = 1, robotnum;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n * 2; i++) {
        int a;
        cin >> a;
        belt.push_back(a);
    }
    while (true) {
        belt.push_front(belt.back());
        belt.pop_back();
        for (int i = robot.size() - 1; i >= 0; i--) {
            robot[i] += 1;
            if (robot[i] == n - 1) robot.pop_back();
        }
        for (int i = robot.size() - 1; i >= 0; i--) {
            int nx = robot[i] + 1;
            if (belt[nx] > 0 && (i == robot.size() - 1 || robot[i + 1] != nx)) {
                robot[i] += 1;
                belt[robot[i]] -= 1;
                if (belt[robot[i]] == 0) cnt++;
                if (robot[i] == n - 1) robot.pop_back();
            }
        }
        if (belt[0] > 0) {
            robot.push_front(0);
            belt[0] -= 1;
            if (belt[0] == 0) cnt++;
        }
        if (cnt >= k) {
            cout << level;
            break;
        }
        level++;
    }
}
