#include <iostream>
#include <string>

using namespace std;

string s = "0",word[7];
int sum[201][201],dp[201][41];
int p,k,n;

int findStr(int l,int r){
    string t = s.substr(l,r - l + 1);
    for(int i = 1;i <= n;i++){
        if(t.find(word[i]) == 0) return 1;
    }
    return 0;
}

void cntNum(){
    for(int i = s.size() - 1;i > 0;i--)
        for(int j = i;j > 0;j--)
            sum[j][i] = sum[j + 1][i] + findStr(j,i);
}

int main(){
    string t;
    cin >> p >> k;
    while(p--){
        cin >> t;
        s += t;
    }
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> word[i];
    }
    cntNum();
    //i -> i
    for(int i = 1;i <= k;i++) dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    //i -> 1
    for(int i = 1;i <= s.size() - 1;i++) dp[i][1] = sum[1][i];
    //i -> j
    for(int i = 1;i <= s.size() - 1;i++)
        for(int j = 1;j <= k;j++)
            for(int l = j;l <= i;l++)
                dp[i][j] = max(dp[i][j],dp[l][j - 1] + sum[l + 1][i]);
    cout << dp[s.size() - 1][k];
    return 0;
}
