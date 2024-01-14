#include <bits/stdc++.h>

using namespace std;

struct mon{
	int i;
	int s;
};

queue<mon> q1;

int main(){
	int m,n,l,a;
	cin >> m;
	l = m;
	for(int i = 1;i <= m;i++){
		cin >> a;
		q1.push({i,(a <= 5 ? 3 : 2)});
	}
	cin >> n;
	while(l - 1){
		for(int i = 0;i < n - 1;i++){
			q1.push(q1.front());
			q1.pop();
		}
		if(q1.front().s > 1){
			q1.front().s -= 1;
			q1.push(q1.front());
			q1.pop();
		}else{
			q1.pop();
			l--;
		}
	}
	cout << q1.front().i;
	return 0;
} 
