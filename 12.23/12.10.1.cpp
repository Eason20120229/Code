#include <bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f

int n,m;
bool e[11][11]; 

int main(){
	cin >> n >> m;
	while(m--){
		int f,t;
		cin >> f >> t;
		e[f][t] =1;
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) e[i][j] = 0;
				e[i][j] = max(e[i][j],e[i][k] && e[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << e[i][j];
		}
		cout << endl;
	}
	return 0;
}


