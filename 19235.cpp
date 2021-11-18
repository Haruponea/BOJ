#include <iostream>
#include <algorithm>
using namespace std;

int n, score;
int green[6][4];
int blue[4][6];

bool remove_green() {
    bool did = false;
    for (int i = 2; i < 6; i++) {
        bool remove = true;
        for (int j = 0; j < 4; j++) {
            if (green[i][j] == 0) remove = false;
        }
        if (remove) {
            did = true;
            score++;
            for (int j = 0; j < 4; j++) {
                green[i][j] = 0;
            }
        }
    }
    return did;
}

bool remove_blue() {
    bool did = false;
    for (int i = 2; i < 6; i++) {
        bool remove = true;
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] == 0) remove = false;
        }
        if (remove) {
            did = true;
            score++;
            for (int j = 0; j < 4; j++) {
                blue[j][i] = 0;
            }
        }
    }
    return did;
}

bool push_green() {
    bool moved = false;
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j] == 1) {
                int nx = i + 1;
                while (true) {
                    if (nx >= 6 || green[nx][j] != 0) break;
                    nx++;
                    moved = true;
                }
                green[i][j] = 0;
                green[nx - 1][j] = 1;
            }
            else if(green[i][j]==2){
                int nx = i + 1;
                while (true) {
                    if (nx >= 6 || green[nx][j] != 0 || green[nx][j+1]!=0) break;
                    nx++;
                    moved = true;
                }
                green[i][j] = green[i][j+1]= 0;
                green[nx - 1][j] = green[nx - 1][j + 1] = 2;
                j++;
            }
        }
    }
    return moved;
}

bool push_blue() {
    bool moved = false;
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] == 1) {
                int ny = i + 1;
                while (true) {
                    if (ny >= 6 || blue[j][ny] != 0) break;
                    ny++;
                    moved = true;
                }
                blue[j][i] = 0;
                blue[j][ny - 1] = 1;
            }
            else if (blue[j][i] == 2) {
                int ny = i + 1;
                while (true) {
                    if (ny >= 6 || blue[j][ny] != 0 || blue[j + 1][ny] != 0) break;
                    ny++;
                    moved = true;
                }
                blue[j][i] = blue[j + 1][i] = 0;
                blue[j][ny - 1] = blue[j + 1][ny - 1] = 2;
                j++;
            }
        }
    }
    return moved;
}

bool check_green() {
    bool checked = false;
    int r = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j] != 0) {
                r = 2 - i;
                checked = true;
                break;
            }
        }
        if (checked) break;
    }
    if (checked) {
        for (int i = 6 - r; i <= 5; i++) {
            for (int j = 0; j < 4; j++)
                green[i][j] = 0;
        }
        push_green();
    }

    return checked;
}

bool check_blue() {
    bool checked = false;
    int c = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] != 0) {
                c = 2 - i;
                checked = true;
                break;
            }
        }
        if (checked) break;
    }
    if (checked) {
        for (int i = 6 - c; i <=5; i++) {
            for (int j = 0; j < 4; j++) {
                blue[j][i] = 0;
            }
        }
        push_blue();
    }
    return checked;
}

void put(int t, int x, int y) {
    if (t == 1) {
        green[0][y] = 1;
        blue[x][0] = 1;
    }
    else if (t == 2) {
        green[0][y] = green[0][y + 1] = 2;
        blue[x][0] = blue[x][1] = 1;
    }
    else {
        green[0][y] = green[1][y] = 1;
        blue[x][0] = blue[x + 1][0] = 2;
    }
    while (true) {
        push_green();
        if (!remove_green()) break;
    }
    while (true) {
        push_blue();
        if (!remove_blue()) break;
    }
    if (check_green()) {
        while (true) {
            push_green();
            if (!remove_green()) break;
        }
    }
    if (check_blue()) {
        while (true) {
            push_blue();
            if (!remove_blue()) break;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while (n--) {
        int t, x, y;
        cin >> t >> x >> y;
        put(t, x, y);
    }

    cout << score<<'\n';
    int g = 0, b = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++) if (green[i][j] != 0) g++;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++) if (blue[i][j] != 0) b++;
    cout << g + b;
}
