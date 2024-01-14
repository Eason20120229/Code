#include <bits/stdc++.h>
using namespace std;

bool dp[11][11];

int main(){
	string s;
	cin >> s;
	int n = s.length();
	int mx = 1;
	for(int i = 0;i < n;i++){
		dp[i][i] = 1;
	}
	for(int i = 0;i < n - 1;i++){
		if(s[i] == s[i + 1]){
			mx = max(mx,2);
			dp[i][i + 1] = 1;
		}
	}
	for(int step = 2;step < n;step++){
		for(int i = 0;i + step < n;i++){
			int j = i + step;
			if(dp[i + 1][j - 1] == 1 && s[i] == s[j]){
				dp[i][j] = 1;
				mx = max(mx,step + 1);
			} 
		}
	}
	cout << mx;
	return 0;
}


