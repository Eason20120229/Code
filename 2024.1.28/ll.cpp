#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;   
}*head,*tail,*pre,*temp,*de;

void create(){
    int n,cnt;
    cin >> n;
    head = tail = new Node;
    tail -> next = nullptr;
    while(n){
        temp = new Node;
        temp -> data = n;
        temp -> next = nullptr;
        tail -> next = temp;
        tail = temp;
        cnt++;
        cin >> n;
    }
    head -> data = cnt;
    temp = nullptr;
}

void output(){
    if(head -> next){
        temp = head -> next;
    }else{
        cout << "The list is empty." << endl;
        return;
    }
    cout << "The list has " << head -> data 
        << " numbers." << endl;
    while (temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    temp = nullptr;
}

void deleteNum(int c){
    int cnt = 0;
    if(head -> next){
        pre = head;
        temp = head -> next;
    }else{
        cout << "The list is empty." << endl;
    }
    while(temp){
        if(temp -> data == c){
            cnt++;
            if(temp -> next){
                pre -> next = temp -> next;
                de = temp;
                temp = temp -> next;
            }else{
                pre -> next = nullptr;
                de = temp;
                temp = nullptr;
                tail = pre;
            }
            delete de;
            de = nullptr;
            continue;
        }
        pre = temp;
        temp = temp -> next;
    }
    pre = nullptr;
    temp = nullptr;
    head -> data -= cnt;
}

int main(){
    create();
    output();
    int t;
    cin >> t;
    deleteNum(t);
    output();
    return 0;
}