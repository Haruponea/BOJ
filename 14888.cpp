#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt, mx=-1000000003, mn=10000000003;
vector<int> nums;
int arr[4];

void func(int level) {
    if (level == n) {
        mx = max(mx, cnt);
        mn = min(mn, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 0) continue;
        if (i == 0) {
            int tmp = cnt;
            arr[i]--;
            cnt += nums[level];
            func(level + 1);
            cnt = tmp;
            arr[i]++;
        }
        else if (i == 1) {
            int tmp = cnt;
            arr[i]--;
            cnt -= nums[level];
            func(level + 1);
            cnt = tmp;
            arr[i]++;
        }
        else if (i == 2) {
            int tmp = cnt;
            arr[i]--;
            cnt *= nums[level];
            func(level + 1);
            cnt = tmp;
            arr[i]++;
        }
        else {
            int tmp = cnt;
            arr[i]--;
            cnt /= nums[level];
            func(level + 1);
            cnt = tmp;
            arr[i]++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    cnt = nums[0];
    func(1);
    cout << mx << '\n' << mn;
}
