#include<bits/stdc++.h>
using namespace std;

int lose[1000001],win[1000001],use[1000001];
int dp[2][1000001];

int main(){
    int n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++){
        cin >> lose[i] >> win[i] >> use[i];
    }
    int ne = 1,old = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= x;j++){
            if(j <= use[i]) continue;
            cout << i << " " << j << " " << dp[old][j] + lose[i] << " " << (dp[old][j - use[i]] + win[i]) << endl;
            dp[ne][j] = max(dp[old][j] + lose[i],
                (dp[old][j - use[i]] + win[i]));
            cout << "h" << endl;
        }
        swap(old,ne);
    }
    cout << dp[n][x] * 5;
    return 0;
}