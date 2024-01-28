#include<bits/stdc++.h>
using namespace std;

int main(){
    string a[6001];
    int cnt = 1,ans = 0;
    while(cin >> a[cnt]) cnt++;
    cnt--;
    sort(a + 1,a + cnt + 1);
    ans += a[1].size();
    for(int i = 2;i <= cnt;i++){
        int k = 0;
        while(k < a[i - 1].size() && a[i][k] == a[i - 1][k]){
            k++;
        }
        cout << a[i] << " ";
        k = a[i].size() - k;
        ans += k;
    }
    ans += 1;
    cout << ans;
    return 0;
}