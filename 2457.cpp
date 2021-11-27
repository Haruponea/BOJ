#include <iostream>
#include <algorithm>
using namespace std;

struct flower {
    int startm;
    int startd;
    int endm;
    int endd;
};

int n;
flower arr[100003];

bool comp(flower a, flower b) {
    if (a.startm == b.startm) {
        if (a.startd == b.startd) {
            if (a.endm == b.endm) {
                return a.endd < b.endd;
            }
            return a.endm < b.endm;
        }
        return a.startd < b.startd;
    }
    return a.startm < b.startm;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].startm >> arr[i].startd >> arr[i].endm >> arr[i].endd;
    }
    int curd, curm, ted,tem;
    curm = tem = 3;
    curd = ted = 1;
    int ans = 0;
    sort(arr, arr + n, comp);
    for (int i = 0; i < n; i++) {
        if (arr[i].endm < curm || (arr[i].endm == curm && arr[i].endd < curd)) continue;
        if (arr[i].startm < curm || (arr[i].startm == curm && arr[i].startd <= curd)) {
            if (tem < arr[i].endm || (tem == arr[i].endm && ted < arr[i].endd)) {
                ted = arr[i].endd;
                tem = arr[i].endm;
            }
            if (tem >= 12) {
                ans++;
                curm = tem;
                curd = ted;
                break;
            }
        }
        else {
            if (arr[i].startm > tem || (arr[i].startm == tem && arr[i].startd > ted)) break;
            curd = ted;
            curm = tem;
            ans++;
            i--;
        }
    }
    if ( curm < 12) ans = 0;
    cout << ans;
}
