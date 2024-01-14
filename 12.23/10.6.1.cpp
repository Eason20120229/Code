#include <bits/stdc++.h>

using namespace std;

queue<int> q1;

int main(){
	int m,n,l;
	cin >> n >> m;
	l = n;
	for(int i = 1;i <= n;i++){
		q1.push(i);
	}
	while(l - 1){
		for(int i = 0;i < m - 1;i++){
			q1.push(q1.front());
			q1.pop();
		}
		q1.pop();
		l--;
	}
	cout << q1.front();
	return 0;
} 
