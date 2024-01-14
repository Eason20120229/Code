#include <bits/stdc++.h>

using namespace std;

int a[4] = {20,10,5,1};

int main(){
	int n,i = 0,ans = 0;
	cin >> n;
	while(n > 0){
		if(n >= a[i]){
			n -= a[i];
			ans++;
		}else{
			i++;
		}
	}
	cout << ans;
	return 0;
}


