#include<bits/stdc++.h>
using namespace std;

bool pr(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    string s;
    string a = "qwertyuiopasdfghjklzxcvbnm";
    cin >> s;
    int maxn = 0;
    long long minn = 0;
    for(int i = 0;i < a.size();i++){
        int cnt = 0;
        for(int j = 0;j < s.size();j++){
            if(s[j] == a[i]) cnt++;
        }
        if(cnt > maxn) maxn = cnt;
        if((cnt < minn || minn == 0) && cnt != 0) minn = cnt;
    }
    if(pr(maxn - minn)) cout << "Lucky Word";
    else cout << "No Answer";
    cout << endl;
    cout << (maxn - minn);
    return 0;
}