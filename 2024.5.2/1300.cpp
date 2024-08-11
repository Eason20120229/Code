#include <iostream>
#include <cstring>

#define mod 1000000007

using namespace std;

char a[1002],b[202];
int n,m,k;
long long res[1001][201][201],ans[1001][201][201];

int main(){
    cin >> n >> m >> k;
    scanf("%s%s",a + 1,b + 1);
    ans[0][0][0] = 1;
    for(int i = 1;i <= n;i++){
        ans[i][0][0] = 1;
        for(int j = 1;j <= m;j++){
            for(int l = 1;l <= k;l++){
                if(a[i] == b[j]){
                    res[i][j][l] = (ans[i - 1][j - 1][l - 1] + res[i - 1][j - 1][l]) % mod;
                }else{
                    res[i][j][l] = 0;
                }
                ans[i][j][l] = (res[i][j][l] + ans[i - 1][j][l]) % mod;
            }
        }
    }
    cout << ans[n][m][k];
    return 0;
}
