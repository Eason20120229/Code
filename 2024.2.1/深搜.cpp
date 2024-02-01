#include<bits/stdc++.h>
using namespace std;

int sx,sy,ex,ey;
char a[100][100];
int book[100][100];
bool f;
int way[4][2] = {1,0,-1,0,0,1,0,-1};
int m,n;

void dfs(int x,int y){
    if(x == ex && y == ey){
        f = true;
        return;
    }
    for(int i = 0;i < 4;i++){
        int tx,ty;
        tx = way[i][0] + x;
        ty = way[i][1] + y;
        if(tx >= 0 && ty >= 0 && tx < m && ty < n
             && !book[tx][ty] && a[tx][ty] == '*'){
            book[tx][ty] = 1;
            dfs(tx,ty);
            book[tx][ty] = 0;
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    if(a[sx][sy] == '*' && a[ex][ey] == '*') dfs(sx,sy);
    if(f) cout << "Yes";
    else cout << "No";
    return 0;
}