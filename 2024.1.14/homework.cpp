#include<bits/stdc++.h>
using namespace std;

struct{
    int w;
    string n;
}data[10001];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> data[i].w >> data[i].n;
    }
    return 0;
}