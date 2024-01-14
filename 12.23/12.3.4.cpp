#include <bits/stdc++.h>
using namespace std;

int g[101][101];
int vis[101],q[101];
int n,e;
int a,b,t;
int sum = 0;

void bfs(int cur);

int main(){
	cin >> n >> e;
	while(e--){
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	cin >> t;
	bfs(t);
	return 0; 
}

void bfs(int cur){
	int h = 0,t = 1;
	q[0] = cur;
	cout << cur << " ";
	vis[cur] = 1;
	while(h < t){
		for(int j = 1;j <= n;j++){
			if((g[q[h]][j] == 1) && (vis[j] == 0)){
				cout << j << " ";
				vis[j] = 1;
				q[t] = j;
				t++;
			}
		}
		h++;
	}
}
