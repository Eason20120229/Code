#include <bits/stdc++.h>

using namespace std;

stack <int> s;

int main(){
	int n,ans,a;
	cin >> n;
	cin >> a;
	s.push(a);
	for(int i = 1;i < n;i++){
		cin >> a;
		if(s.top() > a){
			ans++;
			s.push(a);
		}else{
			int r = s.size();
			while(!s.empty() && s.top() < a){
				s.pop();
				r--;
			}
			ans += s.size() - r + 1;
			s.push(a);
		}
		
	}
	cout << ans;
}
