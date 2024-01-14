#include <bits/stdc++.h>
using namespace std;

void lis(int a[],int n){
	int dp[100] = {};
	fill(dp,dp + n,1);
	for(int i = 2;i < n;i++){
		for(int j = 0;j < i;j++){
			if(a[i] > a[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j];
		}
	}
}

int main(){
	
	return 0;
}


