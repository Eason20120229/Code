#include <bits/stdc++.h>

using namespace std;

long a;

int main(){
	int n,m,ans = 0,t = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a;
		if(t + a <= m){
			t += a;
		}else{
			t = a;
			ans++; 
		}
	} 
	cout << ans + 1;
	return 0;
}


