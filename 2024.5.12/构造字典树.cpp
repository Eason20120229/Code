/* �ֵ��� */
#include<bits/stdc++.h>
using namespace std;
int ch[10000][26];
bool bo[10000];
int tot;
//�����ֵ���
void insert(char *s){
    int len = strlen(s);
    int u=0;
    for(int i=0;i<len;i++){
        int c=s[i]-'a';
        //����ǿսڵ㣬�Ͳ���
        if(!ch[u][c]) ch[u][c] = ++tot;
        u = ch[u][c];//
    }
    bo[u]=1;
}
//�����ֵ���
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
//��ʼ������
void clear(){
    memset(ch,0,sizeof(ch));
    memset(bo,0,sizeof(bo));
}
int main(){
    return 0;
}