#include<bits/stdc++.h>
using namespace std;

struct g{
    int w,v;
    double p;
};

bool cmp(g a,g b){
    return a.p > b.p;
}

int main(){
    int n;
    int c;
    double ans = 0;
    g a[101] = {};
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].w >> a[i].v;
        a[i].p = 1.0 * a[i].v / a[i].w;
    }
    cin >> c;
    sort(a + 1,a + n + 1,cmp);
    int i;
    for(i = 1;i <= n;i++){
        if(c > a[i].w){
            ans += a[i].v;
            c -= a[i].w;
        }else break;
    }
    ans += c * a[i].p;
    printf("%.2f",ans);
    return 0;
}