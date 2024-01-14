#include <bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f

int n,m;
int e[11][11]; 

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i != j) e[i][j] = INF;
		}
	}
	while(m--){
		int f,t,h;
		cin >> f >> t >> h;
		e[f][t] = h;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) e[i][j] = 0;
			for(int k = 1;k <= n;k++){
				e[i][j] = min(e[i][j],e[i][k] + e[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << setw(3) << e[i][j];
		}
		cout << endl;
	}
	return 0;
}


