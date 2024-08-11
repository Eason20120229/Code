#include <iostream>

using namespace std;

int a[301];
int n;

int dp[301][301];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int l = 1;l < n;l++){
        for(int i = 1;i <= 2 * n - l + 1;i++){
            int j = i + l;
            for(int k = i;k < j;k++){
                dp[i][j] = max(
                    dp[i][j],dp[i][k] + dp[k + 1][j] +
                    a[i] * a[k + 1] *
                    a[j + 1]
                );
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,dp[i][i + n - 1]);
    }
    cout << ans;
    return 0;
}
