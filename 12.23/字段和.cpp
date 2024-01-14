#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffff

int main(){
	int sum = 0;
	int ans = -INF;
	int n,k;
	cin >> k >> n;
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		sum += a;
		ans = max(ans,sum);
		if(sum < 0) sum = 0;
	}
	cout << (ans - k);
	return 0;
}


