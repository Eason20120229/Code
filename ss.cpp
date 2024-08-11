#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int w[31] = {0,10,20,50,100};
    int dp[31][1001] = {};
    //for(int i = 0;i <= 4;i++){
    //    dp[i][0] = 1;
    //}
    //for(int i = 0;i <= n;i++) dp[0][i] = 1;
    dp[0][10] = 1;
    dp[1][20] = 1;
    dp[2][50] = 1;
    dp[3][100] = 1;
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 0;w[i] * k <= j;k++){
                dp[i][j] += dp[i - 1][j - w[i] * k];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[4][n];
    return 0;
}
