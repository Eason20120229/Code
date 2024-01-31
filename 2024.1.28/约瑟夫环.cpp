#include<bits/stdc++.h>
using namespace std;

struct Peo{
    int id;
    Peo *next,*pre;
    Peo(){
        next = pre = nullptr;
    }
}n[100];

Peo *_Cut(Peo *num){
    cout << num -> id << " ";
    num = num -> pre;
    num -> next = num -> next -> next;
    num = num -> next;
    num -> pre = num -> pre -> pre;
    return num;
}

int main(){
    int tot,outNum,nowNum = 1;
    Peo *now = n;
    cin >> tot >> outNum;
    for(int i = 1;i < tot - 1;i++){
        n[i].id = i + 1;
        n[i].pre = n + i - 1;
        n[i].next = n + i + 1;
    }
    n[0].pre = n + tot - 1;
    n[0].next = n + 1;
    n[0].id = 1;
    n[tot - 1].pre = n + tot - 2;
    n[tot - 1].next = n;
    n[tot - 1].id = tot;

    while(tot > 0){
        if(nowNum == outNum){
            now = _Cut(now);
            nowNum = 1;
            tot--;
        }else{
            nowNum++;
            now = now -> next;
        }
    }
    return 0;
}