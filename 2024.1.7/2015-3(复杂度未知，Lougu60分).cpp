/*

https://www.luogu.com.cn/problem/P2671

*/

#include<bits/stdc++.h>
using namespace std;

int data[100001];

vector<int> a[100001];
long long sum = 0;

int mod(long long x){
    return x % 10007;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> data[i];
    }
    for(int i = 1;i <= n;i++){
        int c;
        cin >> c;
        a[c].push_back(i);
    }
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < a[i].size() - 1;j++){
            for(int k = j + 1;k < a[i].size();k++){
                int x = a[i][j],z = a[i][k];
                if((x + z) % 2 == 0){
                    int t = mod(data[x] + data[z]);
                    sum += mod(mod(x + z) * t);
                    sum = mod(sum);
                }
            }
        }
    }
    cout << sum;
    return 0;
}


// for(int x = 1;x < n;x++){
//     for(int z = x + 1;z <= n;z++){
//         if((x + z) % 2 == 0 && data[x].c == data[z].c){
//             int t = mod(data[x].n + data[z].n);
//             sum += mod(mod(x + z) * t);
//             sum = mod(sum);
//         }
//     }
// }
// for(int y = 2;y < n;y++){
//     for(int x = 1;x < y;x++){
//         int z = y * 2 - x;
//         if(data[x].c == data[z].c && z <= n){
//             int t = mod(data[x].n + data[z].n);
//             sum += mod(mod(x + z) * t);
//             sum = mod(sum);
//         }
//     }
// }