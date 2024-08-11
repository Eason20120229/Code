#include <cstdio>
#include <iostream>

#define lll __uint128_t

using namespace std;

bool book[100];
char num[1001],x[100],y[100];
int k,len,cnt = 0;

void dfs(char c){
    if(book[c]) return;
    book[c] = 1;
    for(int i = 0;i < k;i++)
        if(x[i] == c)
            dfs(y[i]);
}

void oP(lll sum){
    if(sum > 9) oP(sum / 10);
    printf("%d",sum % 10);
}

int main(){
    lll sum = 1;
    scanf("%s%d",num,&k);
    for(int i = 0;i < k;i++) cin >> x[i] >> y[i];
    for(int i = 0;i < len;i++){ //遍历数字n
        dfs(num[i]);
        lll cnt = 0;
        for(int j = '0';j <= '9';j++){
            cnt += book[j];
            book[j] = 0;
        }
        sum *= cnt;
    }
    oP(sum);
    return 0;
}
