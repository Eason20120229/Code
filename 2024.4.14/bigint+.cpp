
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
    int t = 0;
    while(!a[al] && al > 1) al--;
    while(!b[bl] && bl > 1) bl--;
    int cl = max(al,bl);
    for(int i = 1;i <= cl;i++){
        c[i] = a[i] + b[i] + t;
        t = c[i] / 10;
        c[i] %= 10;
    }
    c[cl + 1] = t;
    if(t) cl++;
    t = 0;
    for(int i = cl;i > 0;i--){
        cout << c[i];
    }
    cout << endl;
    return 0;
}