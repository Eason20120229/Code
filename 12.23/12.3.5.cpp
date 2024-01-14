#include<iostream>
using namespace std;
int g[101][101],d[101];
int n,e;
int a,b;
int sum = 0;

void dfs(int cur){
	cout << cur << " ";
	if(sum == e) return;
	for(int i = 1;i <= n;i++){
		if(g[cur][i] == 1){
			g[i][cur] = 0;
			g[cur][i] = 0;
			sum++;
			dfs(i);
		}
	}
}

int main(){
	int ans = 0,id;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		cin>>a>>b;
		d[a]++;
		d[b]++;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	for(int i = 1;i <= e;i++){
		if(d[i] % 2 == 1){
			ans++;
			id = i;
		}
	}
	if(ans == 2){
		dfs(id);
	}else if(ans == 0){
		dfs(1);
	}else{
		cout << -1;
	}
	
	return 0;
}

