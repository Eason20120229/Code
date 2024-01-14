#include<bits/stdc++.h>
using namespace std;

long long work(int n,int i,int j){
    cout << n << " " << i << " " << j << endl;
    if(i == 1) return j;
    if(j == n) return n + i - 1;
    if(i == n) return 2 * n - 2 + j;
    if(j == 1) return 3 * n - 3 + i;
    return work(n - 2,i - 1,j - 1) + 4 * (n - 1);
}

int main(){
    int n,i,j;
    cin >> n >> i >> j;
    cout << work(n,i,j);
    return 0;
}

/*
1. 1,j = j
2. i,n = n + i - 1
3. n,j = 2 * n - 2 + j
4. i,1 = 3 * n - 3 + i
*/