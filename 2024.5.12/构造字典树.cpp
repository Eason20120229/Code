/* 字典树 */
#include<bits/stdc++.h>
using namespace std;
int ch[10000][26];
bool bo[10000];
int tot;
//创建字典树
void insert(char *s){
    int len = strlen(s);
    int u=0;
    for(int i=0;i<len;i++){
        int c=s[i]-'a';
        //如果是空节点，就插入
        if(!ch[u][c]) ch[u][c] = ++tot;
        u = ch[u][c];//
    }
    bo[u]=1;
}
//搜索字典树
int search(char *s){
    int len = strlen(s);
    int u=0;
    for(int i=0;i<len;i++){
        int c=s[i]-'a';
        if(!ch[u][c]) return 0;
        u = ch[u][c];
    }
    return bo[u];
}
//初始化数组
void clear(){
    memset(ch,0,sizeof(ch));
    memset(bo,0,sizeof(bo));
}
int main(){
    return 0;
}