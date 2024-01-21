#include<bits/stdc++.h>
using namespace std;

struct{
    int w;
    string n;
}data[100001];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> data[i].w >> data[i].n;
    }
    int t = 0;
    for(int i = 0;i < m;i++){
        int w,s;
        cin >> w >> s;
        if(data[t].w == 0) w = (w + 1) % 2;
        if(w == 1) t = (t - s + n) % n;
        if(w == 0) t = (t + s) % n;
    }
    cout << data[t].n;
    return 0;
}