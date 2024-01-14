#include <bits/stdc++.h>
using namespace std;
int mymax = 10000;
int f[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int a[20][20],v[20][20],v1[20][20];
int l = 1;
int n;
bool check(int x1,int y1){
	if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) return false;
	if(a[x1][y1] == 1 || v[x1][y1] > 0) return false;
	return true;
}

void dfs(int x,int y){
	if(x == n - 1 && y == n - 1){
		if(l < mymax){
			mymax = l;
			memcpy(v1,v,sizeof(v1));
		}
		return;
	}
	for(int k = 0;k < 4;k++){
		int x1,y1;
		x1 = x + f[k][0];
		y1 = y + f[k][1];
		if(check(x1,y1)){
			v[x1][y1] = k + 1;
			cout << v[x1][y1]  << " " << k << endl;
			l++;
			dfs(x1,y1);
			l--;
			v[x1][y1] = 0;
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> a[i][j];
		}
	}
	dfs(0,0);
	int k;
	int d = v1[n - 1][n - 1] - 1;
	int x = n - 1,y = n - 1;
	int qn[400][2];
	qn[0][0] = x;
	qn[0][1] = y;
	for(k = 1;;k++){
		x = x - f[d][0];
		y = y - f[d][1];
		qn[k][0] = x;
		qn[k][1] = y;
		d = v1[x][y] - 1;
		if(x == 0 && y == 0) break;
	}
	for(int i = k;i >= 0;i--){
		cout << qn[i][0] << "," << qn[i][1] << endl;
	}
	return 0;
}












