#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	int maxx = -1;
	cin >> s;
	int t = s.length();
	for(int i = 0;i < t;i++){
		int j = 0;
		while(i + j < t && i - j > 0){
			if(s[i + j] == s[i - j]){
				j++;
			}else{
				break;
			}
			
		}
		maxx = max(maxx,j * 2 + 1);
		if(s[i] == s[i + 1]){
			j = 0; 
			while(i + j + 1 < t && i - j > 0){
			if(s[i + j + 1] == s[i - j]){
					j++;
				}else{
					break;
				}
			}
			maxx = max(maxx,j * 2 + 2);	
		}
	}
	cout << maxx;
	return 0;
}


