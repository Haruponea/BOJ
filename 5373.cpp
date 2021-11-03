#include <iostream>
#include <algorithm>
using namespace std;

char board[6][3][3];
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'}; 
bool vis[52][52];

void rotate(char b, char dir) {
    int tmp[3][3];
    int side;
    if (b == 'U')side = 0;
    if (b == 'D')side = 1;
    if (b == 'F')side = 2;
    if (b == 'B')side = 3;
    if (b == 'L')side = 4;
    if (b == 'R')side = 5;

    if (dir == '+') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = board[side][2 - j][i];
            }
        }
    }
    else if (dir == '-') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = board[side][j][2 - i];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[side][i][j] = tmp[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++) 
                for (int k = 0; k < 3; k++) 
                    board[i][j][k] = color[i];
        int n;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            char side = s[0], direction = s[1];
            if (side == 'U') {
                if (direction == '-') {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[2][0][i];
                    for (int i = 0; i < 3; i++) board[2][0][i] = board[4][0][i];
                    for (int i = 0; i < 3; i++) board[4][0][i] = board[3][0][2-i];
                    for (int i = 0; i < 3; i++) board[3][0][i] = board[5][0][2-i];
                    for (int i = 0; i < 3; i++) board[5][0][i] = tmp[i];
                    rotate('U', '-');
                }
                else {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[2][0][i];
                    for (int i = 0; i < 3; i++) board[2][0][i] = board[5][0][i];
                    for (int i = 0; i < 3; i++) board[5][0][i] = board[3][0][2-i];
                    for (int i = 0; i < 3; i++) board[3][0][i] = board[4][0][2-i];
                    for (int i = 0; i < 3; i++) board[4][0][i] = tmp[i];
                    rotate('U', '+');
                }
            }
            else if (side == 'D') {
                if (direction == '-') {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[3][2][i];
                    for (int i = 0; i < 3; i++) board[3][2][i] = board[4][2][2-i];
                    for (int i = 0; i < 3; i++) board[4][2][i] = board[2][2][i];
                    for (int i = 0; i < 3; i++) board[2][2][i] = board[5][2][i];
                    for (int i = 0; i < 3; i++) board[5][2][i] = tmp[2-i];
                    rotate('D', '-');
                }
                else {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[3][2][i];
                    for (int i = 0; i < 3; i++) board[3][2][i] = board[5][2][2-i];
                    for (int i = 0; i < 3; i++) board[5][2][i] = board[2][2][i];
                    for (int i = 0; i < 3; i++) board[2][2][i] = board[4][2][i];
                    for (int i = 0; i < 3; i++) board[4][2][i] = tmp[2-i];
                    rotate('D', '+');
                }
            }
            else if (side == 'F') {
                if (direction == '-') {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][0][i];
                    for (int i = 0; i < 3; i++) board[1][0][i] = board[4][i][2];
                    for (int i = 0; i < 3; i++) board[4][i][2] = board[0][2][2 - i];
                    for (int i = 0; i < 3; i++) board[0][2][i] = board[5][i][0];
                    for (int i = 0; i < 3; i++) board[5][i][0] = tmp[2-i];
                    rotate('F', '-');
                }
                else {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][0][i];
                    for (int i = 0; i < 3; i++) board[1][0][i] = board[5][2 - i][0];
                    for (int i = 0; i < 3; i++) board[5][i][0] = board[0][2][i];
                    for (int i = 0; i < 3; i++) board[0][2][i] = board[4][2 - i][2];
                    for (int i = 0; i < 3; i++) board[4][i][2] = tmp[i];
                    rotate('F', '+');
                }
            }
            else if (side == 'B') {
                if (direction == '-') {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][2][i];
                    for (int i = 0; i < 3; i++) board[1][2][i] = board[5][2 - i][2];
                    for (int i = 0; i < 3; i++) board[5][i][2] = board[0][0][i];
                    for (int i = 0; i < 3; i++) board[0][0][i] = board[4][2-i][0];
                    for (int i = 0; i < 3; i++) board[4][i][0] = tmp[i];
                    rotate('B', '+');
                }
                else {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][2][i];
                    for (int i = 0; i < 3; i++) board[1][2][i] = board[4][i][0];
                    for (int i = 0; i < 3; i++) board[4][i][0] = board[0][0][2-i];
                    for (int i = 0; i < 3; i++) board[0][0][i] = board[5][i][2];
                    for (int i = 0; i < 3; i++) board[5][i][2] = tmp[2 - i];
                    rotate('B', '-');
                }
            }
            else if (side == 'L') {
                if (direction == '-') {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++)tmp[i] = board[1][i][0];
                    for (int i = 0; i < 3; i++)board[1][i][0] = board[3][2 - i][0];
                    for (int i = 0; i < 3; i++) board[3][i][0] = board[0][2-i][0];
                    for (int i = 0; i < 3; i++)board[0][i][0] = board[2][i][0];
                    for (int i = 0; i < 3; i++) board[2][i][0] = tmp[i];
                    rotate('L', '-');
                }
                else {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][i][0];
                    for (int i = 0; i < 3; i++) board[1][i][0] = board[2][i][0];
                    for (int i = 0; i < 3; i++) board[2][i][0] = board[0][i][0];
                    for (int i = 0; i < 3; i++) board[0][i][0] = board[3][2-i][0];
                    for (int i = 0; i < 3; i++) board[3][i][0] = tmp[2-i];
                    rotate('L', '+');
                }
            }
            else if (side == 'R') {
                if (direction == '-') {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][i][2];
                    for (int i = 0; i < 3; i++) board[1][i][2] = board[2][i][2];
                    for (int i = 0; i < 3; i++) board[2][i][2] = board[0][i][2];
                    for (int i = 0; i < 3; i++) board[0][i][2] = board[3][2 - i][2];
                    for (int i = 0; i < 3; i++) board[3][i][2] = tmp[2 - i];
                    rotate('R', '-');
                }
                else {
                    char tmp[3] = {};
                    for (int i = 0; i < 3; i++) tmp[i] = board[1][i][2];
                    for (int i = 0; i < 3; i++) board[1][i][2] = board[3][2 - i][2];
                    for (int i = 0; i < 3; i++) board[3][i][2] = board[0][2 - i][2];
                    for (int i = 0; i < 3; i++) board[0][i][2] = board[2][i][2];
                    for (int i = 0; i < 3; i++) board[2][i][2] = tmp[i];
                    rotate('R', '+');
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[0][i][j];
            }
            cout << '\n';
        }
    }
}
