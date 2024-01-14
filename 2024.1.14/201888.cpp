#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j;
    cin >> n >> i >> j;
    int c = min(min(i,n - i + 1),min(j,n - j + 1));
    int ans = 4 * (n - c + 1) * (c - 1);
    if(i == c) ans += j - c + 1;
    else if(j == n - c + 1) ans += n - 3 * c + i + 2;
    else if(i == n - c + 1) ans += 3 * n - 5 * c - j + 4;
    else if(j == c) ans += 4 * n - 7 * c - i + 5;
    cout << ans;
    return 0;
}

/*
1. 1,j = j
2. i,n = n + i - 1
3. n,j = 2 * n - 2 + j
4. i,1 = 3 * n - 3 + i
*/