#include <iostream>
#include <algorithm>
using namespace std;
int n, l, ans;
int arr[102][102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n>>l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        bool possible = true;
        int curh = arr[i][0];
        int curd = 1;
        for (int j = 1; j < n; j++) {
            if (arr[i][j] == curh) {
                curd += 1;
            }
            else if (arr[i][j] < curh) {
                if (curh - arr[i][j] != 1) {
                    possible = false;
                    break;
                }
                int nxth = arr[i][j];
                for (int k = j; k < j + l; k++) {
                    if(k>=n || arr[i][k] != nxth){
                        possible = false;
                        break;
                    }

                }
                if (!possible)
                    break;
                else {
                    curd = 0;
                    curh = nxth;
                    j = j + l - 1;
                }
            }
            else if (arr[i][j] > curh) {
                if (arr[i][j]-curh != 1) {
                    possible = false;
                    break;
                }
                if (curd >= l) {
                    curh = arr[i][j];
                    curd = 1;
                }
                else {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) { ans++; }
    }
    for (int j = 0; j < n; j++) {
        bool possible = true;
        int curh = arr[0][j];
        int curd = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i][j] == curh) {
                curd += 1;
            }
            else if (arr[i][j] < curh ) {
                if (curh - arr[i][j] != 1) {
                    possible = false;
                    break;
                }
                int nxth = arr[i][j];
                for (int k = i; k < i + l; k++) {
                    if (k >= n || arr[k][j] != nxth) {
                        possible = false;
                        break;
                    }

                }
                if (!possible)
                    break;
                else {
                    curd = 0;
                    curh = nxth;
                    i = i + l - 1;
                }
            }
            else if (arr[i][j] > curh) {
                if (arr[i][j] - curh != 1) {
                    possible = false;
                    break;
                }
                if (curd >= l) {
                    curh = arr[i][j];
                    curd = 1;
                }
                else {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) { ans++; }
    }
    cout << ans;
}
