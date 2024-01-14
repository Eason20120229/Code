#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y,s;
};

queue<node> q;
int g[101][101];
int xy[4][2] = {0,1,0,-1,1,0,-1,0};

int main(){
    int n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> g[i][j];
        }
    }
    int x,y;
    int ans = 0;
    cin >> x >> y;
    if(g[x][y] == 0){
        cout << 0;
        return 0;
    }
    q.push({x,y,s});
    while(s--){
        node t = q.front();
        for(int i = 0;i < 4;i++){
            int tx = t.x + xy[i][0];
            int ty = t.y + xy[i][1];
            if(tx <= 0 || ty <= 0 || 
                ty > n || tx > n) continue;
            cout << q.back().s << endl;
            if(g[tx][ty] && t.s > 0){
                q.push({tx,ty,t.s + 1});
                g[tx][ty] = 0;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}