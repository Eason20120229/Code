/*

输入：
4


*/



#include<bits/stdc++.h>
using namespace std;

int h[101];
int f[1010][40400];
int p = 20000;
int mod = 98244353;

int main(){
    int n,ans;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> h[i];
    }
    for(int i = 1;i <= n;i++){
        ans++;
        for(int j = i - 1;j;j--){
            f[i][h[i] - h[j] + p] += f[j][h[i] - h[j] + p] + 1;
            ans += f[j][h[i] - h[j] + p] + 1;
            f[i][h[i] - h[j] + p] %= mod;
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}