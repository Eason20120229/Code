#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10]; 

int main(){
	cin >> m >> n;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(i == 0 || j == 0){
				a[j] = 1;
			}else{
				a[j] = a[j] + a[j - 1]; 
			}
		}
	}
	cout << a[n - 1];
	return 0;
}


