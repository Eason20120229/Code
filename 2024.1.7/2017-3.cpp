/*
https://www.luogu.com.cn/problem/P3956
最短路径剪枝
*/
#include<bits/stdc++.h>
using namespace std;

int g[101][101];
int book[101][101];
int d[101][101];
int w[4][2] = {0,1,0,-1,1,0,-1,0};
int n,m;
int ans = -1;

void dfs(int x,int y,int t,int f,int f2){
    //cout << x << " " << y << " " << f << " " << f2 << endl;
    if(x == n && y == n){
        if(ans == -1) ans = t;
        else ans = min(ans,t);
        return;
    }
    if(d[x][y] <= t) return;
    d[x][y] = t;
    for(int i = 0;i < 4;i++){
        int tx = x + w[i][0];
        int ty = y + w[i][1];
        if(tx > 0 && ty > 0 && tx <= n && ty <= n && 
            !book[tx][ty]){
            book[x][y] = 1;
            if(g[tx][ty] == 0 && f2 == 0){
                dfs(tx,ty,t + 2,f,1);
            }else if(g[tx][ty]){
                if(f != g[tx][ty]) 
                    dfs(tx,ty,t + 1,g[tx][ty],0);
                else
                    dfs(tx,ty,t,f,0);
            }
            book[x][y] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    memset(d,0x7f,sizeof(d));
    while(m--){
        int x,y,c;
        cin >> x >> y >> c;
        g[x][y] = c + 1;
    }
    dfs(1,1,0,g[1][1],0);
    cout << ans;
    return 0;
}