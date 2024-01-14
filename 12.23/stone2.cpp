#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int g = 0;
int dp[10001];

bool dfs(int n){
	if(dp[n]) return dp[n] - 1;
	if(n <= 3){
		dp[n] = 2;
		return true;
	}
	for(int i = 1;i <= 3;i++){
		if(!dfs(n - i)){
			dp[n] = 2;
			return true;
		}
	}
	dp[n] = 1;
	return false;
}

int main(){
	int n;
	cin >> n;
	g = dfs(n);
	if(g) cout << "Yes";
	else cout << "No";
	return 0;
}


