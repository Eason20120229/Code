#include <bits/stdc++.h>

using namespace std;

int D[100];

int main(){
	int n,last = 0,m,now;
	cin >> n; 
	for(int i = 0;i < n;i++){
		cin >> now;
		D[i] = now - last;
		last = now;
	}
	cin >> m;
	while(m--){
		int l,r,d;
		cin >> l >> r >> d;
		D[l] += d;
		D[r] -= d;
	}
	int t,sum = 0;
	cin >> t;
	for(int i = 0;i < t;i++){
		sum += D[i];
	}
	cout << sum;
	return 0;
}


