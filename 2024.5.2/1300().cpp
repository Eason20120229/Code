#include <iostream>
#include <cstring>

#define mod 1000000007

using namespace std;

char a[1002],b[202];
int n,m,k;
long long res[2][210][210],ans[2][210][210];

int main(){
    cin >> n >> m >> k;
    scanf("%s%s",a + 1,b + 1);
    ans[0][0][0] = 1;
    for(int i = 1;i <= n;i++){
        int now = i % 2;
        ans[now][0][0] = 1;
        for(int j = 1;j <= m;j++){
            for(int l = 1;l <= k;l++){
                if(a[i] == b[j]){
                    res[now][j][l] = (ans[1 - now][j - 1][l - 1] + res[1 - now][j - 1][l]) % mod;
                }else{
                    res[now][j][l] = 0;
                }
                ans[now][j][l] = (res[now][j][l] + ans[1 - now][j][l]) % mod;
            }
        }
    }
    cout << ans[n % 2][m][k];
    return 0;
}
