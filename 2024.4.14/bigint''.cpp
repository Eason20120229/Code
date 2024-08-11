#include <bits/stdc++.h>

using namespace std;

bool cmp(int *a,int *b){
    if(a[0] < b[0]) return 1;
    else if(a[0] == b[0]){
        for(int i = a[0];i > 0;i--){
            if(a[i] < b[i]) return 1;
            else if(a[i] > b[i]) return 0;
        }
    }
    return 0;
}

void jian(int *a,int *b,int *c){
    int t = 0;
    c[0] = max(a[0],b[0]);
    for(int i = 1;i <= c[0];i++){
        c[i] = a[i] - b[i] + t;
        if(c[i] < 0){
            t = -1;
            c[i] += 10;
        }else t = 0;
    }
    while(!c[c[0]] && c[0] > 1) c[0]--;
}

void chu(int *a,int *b,int *c){
    int tmp[100001] = {};
    c[0] = a[0];
    int k = a[0];
    while(!cmp(a,b) && k){
        copy(a + k,a + a[0] + 1,tmp + 1);
        tmp[0] = a[0] - k + 1;
        // for(int i = a[0];i >= k;i--){
        //     cout << a[i];
        // }
        // cout << endl;
        while(!cmp(tmp,b)){
            // cout << k << ":";
            // for(int i = tmp[0];i > 0;i--){
            //     cout << tmp[i];
            // }
            // cout << endl;
            tmp[0] = a[0] - k + 1;
            jian(tmp,b,tmp);
            c[k]++;
            int t = 0;
            for(int i = k;i <= c[0];i++){
                c[i] += t;
                t = c[i] / 10;
                c[i] %= 10;
                if(!t) break;
            }
        }
        copy(tmp + 1,tmp + a[0] - k + 2,a + k);
        memset(tmp,0,sizeof(tmp));
        while(!a[a[0]] && a[0] > 1) a[0]--;
        k--;
    }
    while(!c[c[0]] && c[0] > 1) c[0]--;
}

int main(){
    char sa[100001],sb[100001];
    int a[100001] = {},b[100001] = {};
    int c[100001] = {};
    cin >> sa >> sb;
    a[0] = strlen(sa),b[0] = strlen(sb);
    for(int i = 0;i < a[0];i++)
        a[a[0] - i] = sa[i] - '0';
    for(int i = 0;i < b[0];i++)
        b[b[0] - i] = sb[i] - '0';
    while(!a[a[0]] && a[0] > 1) a[0]--;
    while(!b[b[0]] && b[0] > 1) b[0]--;
    chu(a,b,c);
    for(int i = c[0];i > 0;i--){
        cout << c[i];
    }
    return 0;
}
