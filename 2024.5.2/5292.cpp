#include <iostream>
#include <string>

using namespace std;

string u[7];
string a = "";
int sum[301][301];
int best;
int dp[301][301];
int p,k,s;

int cntNum(int l,int r){
    int sum = 0;
    for(int i = l;i <= r;i++){
        for(int j = 1;j <= s;j++){
            if(i + u[j].size() - 1 <= r){
                t = a.substr(i,u[j].size());
                if(t == u[j]){
                    sum++;
                    break;
                }
            }
        }
    }
    return sum;
}

void dfs(int i,int x,int su){
    if(a.size() - i + 1 < k - x) return;
    if(i == k){
        su += sum[x + 1][a.size()];
        best = max(best,su);
        return;
    }
    for(int j = x + 1;j <= a.size();j++){
        dfs(i + 1,j,su + sum[x][j]);
    }
}

int main(){
    string c;
    cin >> p >> k;
    while(p--){
        cin >> c;
        a += c;
    }
    cin >> s;
    for(int i = 1;i <= s;i++){
        cin >> u[i];
    }
    for(int i = 0;i < a.size();i++){
        for(int j = i;j < a.size();j++)
            sum[i + 1][j + 1] = cntNum(i,j);
    }
    dfs(1,0,0);
    cout << best;
    return 0;
}
