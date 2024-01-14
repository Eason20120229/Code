#include <bits/stdc++.h>

using namespace std;

string s;
int f[100][100];

int dp(int l,int r){
	int i = l,j = r;
	while(i < j){
		if(s[i] == '('){
			if(s[j] == ')'){
				i++;
				j--;
				if(!f[i][j]){
					int d = dp(i,j); 
					f[i][j] = d + 1;
					if(!d){
						return 0;
					}
				}else{
					if(!(f[i][j] - 1)){
						return 0;
					}
				}
				if(j + 2 <= r){
					if(!f[j + 2][r]){
						int d = dp(j + 2,r); 
						f[j + 2][r] = d + 1;
						if(!d){
							return 0;
						}
					}else{
						if(!(f[j + 2][r] - 1)){
							return 0;
						}
					}
				}
			}else{
				j--;
			}
		}
		if(s[i] == '['){
			if(s[j] == ']'){
				i++;
				j--;
				if(!f[i][j]){
					int d = dp(i,j); 
					f[i][j] = d + 1;
					if(!d){
						return 0;
					}
				}else{
					if(!(f[i][j] - 1)){
						return 0;
					}
				}
				if(!f[j + 1][r]){
					int d = dp(j + 1,r); 
					f[j + 1][r] = d + 1;
					if(!d){
						return 0;
					}
				}else{
					if(!(f[j + 1][r] - 1)){
						return 0;
					}
				}
			}else{
				j--;
			}
		}
	}
	i--;
	j++;
	if(s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']'){
		return 1;
	}
	return 0;
}


int main(){
	cin >> s;
	if(dp(0,s.length() - 1)){
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}
