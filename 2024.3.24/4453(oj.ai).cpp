#include<bits/stdc++.h>
using namespace std;
struct k{
    int a,b;
};

bool cmp(k a,k b){
    return (a.a / a.b) < (b.a / b.b);
}

int main(){
    k a[101];
    int n,l,sum = 0;
    cin >> n >> l;
    for(int i = 1;i <= n;i++){
        int j,b;
        cin >> j >> b;
        a[i].a = j;a[i].b = b;
    }
    sort(a + 1,a + n + 1,cmp);
    int t = l;
    for(int i = n;i > 0 && t;i--){
        if(t >= a[i].b){
            t -= a[i].b;
            sum += a[i].a;
        } else{
            sum += t * (a[i].a / a[i].b);
            t = 0;
            break;
        }
    }
    cout << sum;
    return 0;
}

/**
* @runId: 2950780
* @language: C++
* @author: Eason2012
* @submitTime: 2024-03-24 14:25:44
*/
