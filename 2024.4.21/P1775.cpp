#include <iostream>

using namespace std;

int a[301],b[301],dp[301][301];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j) continue;
            dp[i][j] = 0x7ffffff;
        }
    }
    for(int l = 1;l < n;l++){
        for(int i = 1;i <= n - l;i++){
            for(int k = i;k <= i + l;k++){
                dp[i][i + l] = min(dp[i][i + l],dp[i][k] + dp[k + 1][i + l] + b[i + l] - b[i - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
