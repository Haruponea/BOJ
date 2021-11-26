#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s;
int mx=-(1<<31), n;

bool bracket[12];
char op[12];
int num[12];
int numlen, oplen;
int calc(int a, char op, int b) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else 
        return a * b;
}

void func(int level) {
    if (level >= oplen) {
        vector<char> op_tmp;
        vector<int>num_tmp;
        vector<char> op_tmp2;
        vector<int>num_tmp2;
        int cur = num[0];
        for (int i = 0; i < oplen; i++) {
            if (bracket[i] == true) {
                num_tmp.push_back(calc(num[i], op[i], num[i + 1]));
                if(i != oplen-1){
                    op_tmp.push_back(op[++i]);
                    if (i == oplen - 1)
                        num_tmp.push_back(num[i + 1]);
                }
            }
            else {
                op_tmp.push_back(op[i]);
                num_tmp.push_back(num[i]);
                if (i == oplen - 1)
                    num_tmp.push_back(num[i + 1]);
            }
        }
        if (!num_tmp.empty()) {
            num_tmp2.push_back(num_tmp[0]);
            for (int i = 0; i < op_tmp.size(); i++) {
                if (op_tmp[i] == '*') {
                    int tmp = num_tmp2.back(); num_tmp2.pop_back();
                    tmp = calc(tmp, '*', num_tmp[i + 1]);
                    num_tmp2.push_back(tmp);
                }
                else {
                    num_tmp2.push_back(num_tmp[i + 1]);
                    op_tmp2.push_back(op_tmp[i]);
                }
            }
        }
        if (!num_tmp2.empty()) {
            cur = num_tmp2[0];
            for (int i = 0; i < op_tmp2.size(); i++) {
                cur = calc(cur, op_tmp2[i], num_tmp2[i + 1]);
            }
        }
        mx = max(mx, cur);
        return;
    }
    else {
        func(level + 1);

        bracket[level] = true;
        func(level + 2);
        bracket[level] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n>> s;
    for (int i = 0; i < n; i++) {
        if ('0' <= s[i] && s[i] <= '9') num[numlen++] = s[i] - '0';
        else op[oplen++] = s[i];
    }
    func(0);
    cout << mx;
}
