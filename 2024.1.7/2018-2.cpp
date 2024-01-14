#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100001];
ll ans = 0,h = 0x7fffffff;

int main(){
    ll n,m,p1,s1,s2;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    ll c = 0;
    for(int i = 1;i < m;i++){
        c += a[i] * (m - i);
    }
    for(int i = m + 1;i <= n;i++){
        c -= a[i] * (i - m);
    }
    int i = 1;
    if(i < m){
        ll t = abs(c + s2 * (m - i));
        if(h > t){
            h = t;
            ans = i;
        }
    }else if(m < i){
        ll t = abs(c - s2 * (i - m));
        if(h > t){
            h = t;
            ans = i;
        }
    }else{
        ll t = abs(c);
        if(h > t){
            h = t;
            ans = i;
        }
    }
    for(int i = 2;i <= n;i++){
        if(i < m){
            ll t = abs(c + s2 * (m - i));
            if(h > t){
                h = t;
                ans = i;
            }
        }else if(m < i){
            ll t = abs(c - s2 * (i - m));
            if(h > t){
                h = t;
                ans = i;
            }
        }else{
            ll t = abs(c);
            if(h > t){
                h = t;
                ans = i;
            }
        }
    }
    cout << ans;
    return 0;
}