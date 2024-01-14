#include <bits/stdc++.h>

using namespace std;

stack <int> s;

int main(){
	
	for(int i = 1;i <= 5;i++){
		s.push(i);
	}
	cout << s.size() << endl;
	s.pop();
	s.pop();
	cout << s.top() << endl;
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
} 
