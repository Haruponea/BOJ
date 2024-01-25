#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a;
	int n;
	cin>>n;
	
	while(n--){
	stack<char> s;
	bool val=true;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]=='(' || a[i]=='['){
			s.push(a[i]);
		}
		else if(a[i]==')'){
			if(s.empty() || s.top()!='('){
				val=false;
				break;
			}
			else s.pop();
		}
		else if(a[i]==']'){
			if(s.empty()|| s.top()!='['){
				val=false;
				break;
			}
			else{
				s.pop();
			}
		}
	}
	
	if(!s.empty()) val=false;
	
	if(val) cout<<"YES\n";
	else cout<<"NO\n";
}
}
