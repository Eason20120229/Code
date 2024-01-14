#include <bits/stdc++.h>

using namespace std;

stack<int>s;

int main(){
	int n,c,a;
	cin >> n >> c;
	for(int i = 0;i < n;i++){
		cin >> a;
		if((s.empty() || s.top() > a) && s.size() <= c) s.push(a);
		else if(s.top() < a){
			while(!s.empty() && s.top() < a){
				cout << s.top() << " ";
				s.pop();
			}
			s.push(a);
		}else{
			cout << s.top() << " ";
			s.pop();
			s.push(a);
		}
	}
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
