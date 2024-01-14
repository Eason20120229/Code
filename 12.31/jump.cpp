#include<bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;

int main(){
    int n;
    cin >> n;
    int a[100] = {};
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> t = q.front();
        q.pop();
        if(n - 1 - t.first <= a[t.first]){
            cout << t.second + 1;
            break;
        }
        for(int i = 1;i <= a[t.first];i++){
            q.push({t.first + i,t.second + 1});
        }
    }
    return 0;
}