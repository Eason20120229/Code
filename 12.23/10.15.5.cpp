#include <bits/stdc++.h>

using namespace std;

int a[10000];
int dp[10000];

int main(){
	int n,i = 0,ans = 0,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		long long min = 0x7f7f7f;
		for(int j = 0;j < m;j++){
			if(i >= dp[j]){
				if(1 + dp[i - a[j]] < min){
					min = 1 + dp[i - a[j]];
				}
			}
			dp[i] = min;
		}
	}
	cout << dp[n];
	return 0;
}


