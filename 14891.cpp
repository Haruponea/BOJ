#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

deque<int> arr[4];

void rotate(int idx, int dir) {
    if (dir == -1) {
        arr[idx].push_back(arr[idx].front());
        arr[idx].pop_front();
    }
    else if (dir == 1) {
        arr[idx].push_front(arr[idx].back());
        arr[idx].pop_back();
    }
    else return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            arr[i].push_back(s[j] - '0');
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int dirs[4] = {};
        int num, dir;
        cin >> num >> dir;
        num--;
        dirs[num] = dir;
        int l = num - 1;
        int r = num + 1;
        int tmp = num;
        while (r < 4) {
            if (arr[tmp][2] != arr[r][6]) {
                dirs[r] = -dirs[tmp];
                tmp = r;
                r += 1;
            }
            else 
                break;
        }
        tmp = num;
        while (l >= 0) {
            if (arr[tmp][6] != arr[l][2]) {
                dirs[l] = -dirs[tmp];
                tmp = l;
                l -= 1;
            }
            else 
                break;
        }
        for (int i = 0; i < 4; i++) {
            rotate(i, dirs[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i][0] == 1) {
            ans += (1 << i);
        }
    }
    
    cout << ans;
}
