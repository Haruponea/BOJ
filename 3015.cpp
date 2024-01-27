#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    long long ans = 0;
    cin >> n;
    stack<pair<int, int>> st; //<높이, 이어진 같은 높이의 수>
    while (n--)
    {
        int cnt = 1; // 같은 높이의 수
        cin >> h;
        while (!st.empty() && st.top().first <= h)
        {
            if (st.top().first < h)
            {
                ans += st.top().second;
                st.pop();
            }
            else
            { // st.top.first==h
                ans += st.top().second;
                cnt += st.top().second;
                st.pop();
            }
        }
        /*스택이 비어있다면 지금 입력된 사람이 가장 큰 사람이므로 위에서 처리가 다 되었고, 
        스택이 비어있지 않다면 지금 입력된 사람보다 큰 사람이 스택에 남아있다는 것이고 이 사람과
        가장 최근에 입력된 사람이 쌍을 이루므로 ans++를 해주어야한다.*/
        if (!st.empty())
            ans++;
        st.push(make_pair(h, cnt));
    }
    cout << ans;
}
