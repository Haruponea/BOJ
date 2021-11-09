#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    int board[12][12] = { 0, };
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    int arr[3][22] = { 0, };
    for (int i = 0; i < 20; i++) cin >> arr[1][i];
    for (int i = 0; i < 20; i++) cin >> arr[2][i];
    for (int i = 0; i < n; i++)  arr[0][i] = i+1;

    do {
        int win[3] = { 0, };
        int idx[3] = { 0, };
        int p1 = 0, p2 = 1;
        while (true) {
            if (idx[0] > n) break;
            if (p1 > p2) swap(p1, p2);
            int hand1 = arr[p1][idx[p1]++];
            int hand2 = arr[p2][idx[p2]++];
            if (board[hand1][hand2] == 0 || board[hand1][hand2] == 1) {
                win[p2]++;
                if (win[p2] == k) {
                    break;
                }
                p1 = 3 - p1 - p2;
            }
            else {
                win[p1]++;
                if (win[p1] == k) {
                    break;
                }
                p2 = 3 - p1 - p2;
            }
        }
        if (win[0] == k) {
            cout << 1;
            return 0;
        }
    } while (next_permutation(arr[0], arr[0] + n));
    cout << 0;
}
