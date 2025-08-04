/*
https://github.com/encrypted-def/basic-algo-lecture/blob/master/Appendix%20D/union-find.cpp
path compression & union by rank
*/
vector<int> p(1000001, -1);

int find(int x){
  if(p[x] < 0)
    return x;
  return p[x] = find(p[x]);
}

bool uni(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v)
    return false;
  if(p[v] < p[u]) // v의 랭크가 더 큰 경우
    swap(u, v); // u, v를 swap
  // 위의 if문으로 인해 u의 랭크 >= v의 랭크이다
  if(p[u] == p[v]) // 랭크가 같은 경우에 대한 처리
    p[u]--;
  p[v] = u; // v를 u의 자식으로 만든다  
  return true;  
}

/*
https://www.acmicpc.net/problem/1717
only path compression
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;

vector<int> v;

int grp(int k) {
    if((k==v[k])) return k;
    return v[k] = grp(v[k]);
}

void join(int a, int b) {
	int aRoot = grp(a);
	int bRoot = grp(b);
	v[bRoot] = aRoot;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>m;
	for (int i = 0; i <= n; i++) {
		v.push_back({i});
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a) {
			if (grp(b) == grp(c)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else {
			join(b, c);
		}
	}


	return 0;
}
