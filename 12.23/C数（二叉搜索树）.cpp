#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int **dp;

int main(){
	int n;
	cin >> n;
	dp = new int *[n + 1];
	for(int i = 0;i <= n;i++){
		dp[i] = new int[n + 1];
		for(int j = 0;j <= n;j++){
			dp[i][j] = 0;
			if(i == j) dp[i][j] = 1;
		}
	}
	for(int s = 1;s <= n;s++){
		for(int i = 1;i + s <= n;i++){
			int j = i + s;
			dp[i][j] += dp[i + 1][j];
			dp[i][j] += dp[i][j - 1];
			for(int k = i + 1;k < j;k++){
				dp[i][j] += dp[i][k - 1] * dp[k + 1][j];
			}
		}
	}
	cout << dp[1][n];
	return 0;
}


