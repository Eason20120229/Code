#include <iostream>
#include <cstring>

using namespace std;

int ch[100001][20];
int bo[100001];
int cnt = 0;

void insert(char *s){
    int u = 0;
    for(int i = 0;i < strlen(s);i++){
        if(!ch[u][s[i] - '0']) ch[u][s[i] - '0'] = ++cnt;
        u = ch[u][s[i] - '0'];
        bo[u]++;
    }
}

int search(char *s){
    int u = 0;
    for(int i = 0;i < strlen(s);i++){
        if(!ch[u][s[i] - '0']) return 0;
        u = ch[u][s[i] - '0'];
    }
    if(!bo[u] || bo[u] - 1 > 0) return 1;
    return 0;
}

int main(){
    char s[10001][11] = {};
    int t,n;
    cin >> t;
    while(t--){
        bool k = 0;
        memset(ch,0,sizeof(ch));
        memset(bo,0,sizeof(bo));
        cnt = 0;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> s[i];
            insert(s[i]);
        }
        for(int i = 0;i < n;i++){
            if(search(s[i])){
                k = 1;
                break;
            }
        }
        if(k) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
