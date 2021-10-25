#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, k, r, c, cnt;
int sticker[102][102];
int tilted[102][102];
int note[102][102];

void tilt() {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            tilted[i][j] = sticker[r-j-1][i];
        }
    }
    swap(r, c);
    swap(sticker, tilted);
}

bool possible(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (note[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1) {
                cnt++;
                note[x + i][y + j] = 1;
            }
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        for (int a = 0; a < r; a++)
            for (int b = 0; b < c; b++)
                cin >> sticker[a][b];
        bool p = false;
        for (int t = 0; t < 4; t++) {
            for (int a = 0; a <= n - r; a++) {
                for (int b = 0; b <= m - c; b++) {
                    p = possible(a, b);
                    if (p) break;
                }
                if (p) break;
            }
            if (p) break;
            tilt();
        }
    }
    cout << cnt;
}
