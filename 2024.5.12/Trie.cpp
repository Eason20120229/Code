#include <iostream>
#include <cstring>

using namespace std;

int ch[10001][26];
int bo[10001];
int cnt = 0;

void insert(char *s){
    int u = 0;
    for(int i = 0;i < strlen(s);i++){
        if(!ch[u][s[i] - 'a']) ch[u][s[i] - 'a'] = ++cnt;
        u = ch[u][s[i] - 'a'];
    }
    bo[u]++;
}

int search(char *s){
    int u = 0;
    for(int i = 0;i < strlen(s);i++){
        if(!ch[u][s[i] - 'a']) return 0;
        u = ch[u][s[i] - 'a'];
    }
    return bo[u];
}

int main(){
    char s[10001] = {};
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> s;
        insert(s);
    }
    for(int i = 0;i < n;i++){
        cin >> s;
        cout << search(s) << endl;
    }
    return 0;
}
