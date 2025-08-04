/*
https://www.acmicpc.net/problem/2252
*/
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, m;
vector<int> v[32003];
queue<int> q;
int indegree[32003];
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push(i);
	}

	while(!q.empty()){
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int nxt : v[cur]) {// 간선 삭제를 통해 indegree값 갱신
			if (!--indegree[nxt]) q.push(nxt);//indegree값이 0인 경우
		}
	}

  if(ans.size()!=n){
    cout<<"cycle exist";
  }
  else{
    for(int x: ans) cout << x << ' ';
  }
  return 0;
}
