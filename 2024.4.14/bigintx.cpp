#include <bits/stdc++.h>

using namespace std;

int main(){
    char sa[1000],sb[1000];
    int a[1001] = {},b[1001] = {},c[1001] = {};
    cin >> sa >> sb;
    int al = strlen(sa),bl = strlen(sb);
    for(int i = 0;i < al;i++)
        a[al - i] = sa[i] - '0';
    for(int i = 0;i < bl;i++)
        b[bl - i] = sb[i] - '0';
    while(!a[al] && al > 1) al--;
    while(!b[bl] && bl > 1) bl--;
    int cl = al + bl + 1;
    for(int i = 1;i <= bl;i++){
        int x = 0;
        for(int j = 1;j <= al;j++){
            c[i + j - 1] += a[j] * b[i] + x;
            x = c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
        c[i + al] += x;
    }
    while(!c[cl] && cl > 1) cl--;
    for(int i = cl;i > 0;i--){
        cout << c[i];
    }
    cout << endl;
    return 0;
}
