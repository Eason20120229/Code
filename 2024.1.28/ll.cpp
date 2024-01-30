#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;   
};

Node *head,*tail,*pre,*temp,*de,*nextNode;

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

void outPut(){
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

void headInsert(int n){
    temp = new Node;
    if(!head -> next){
        head -> next = temp;
        temp -> data = n;
        temp -> next = nullptr;
        tail = temp;
        head -> data++;
        return;
    }
    temp -> next = head -> next;
    head -> next = temp;
    temp -> data = n;
    head -> data++;
}

void tailInsert(int n){
    temp = new Node;
    tail -> next = temp;
    temp -> next = nullptr;
    temp -> data = n;
    head -> data++;
}

void insertODUp(int n){
    if(!head -> next){
        temp = new Node;
        head -> next = temp;
        temp -> data = n;
        temp -> next = nullptr;
        tail = temp;
        head -> data++;
        return;
    }
    pre = head;
    temp = pre -> next;
    while(temp){
        if(temp -> data > n){
            pre -> next = new Node;
            pre = pre -> next;
            pre -> data = n;
            pre -> next = temp;
            head -> data++;
            return;
        }
        if(!temp -> next) tailInsert(n);
        pre = temp;
        temp = temp -> next;
    }
}

void reverseList(){
    Node *cur = head -> next;
    tail = cur;
    head -> next = nullptr;
    while(cur){
        nextNode = cur -> next;
        cur -> next = head -> next;
        head -> next = cur;
        cur = nextNode;
    }
}

void sort(){
    for(int i = 0;i < head -> data;i++){
        temp = head -> next;
        for(int j = 0;j < head -> data - i - 1;j++){
            if(temp -> data > temp -> next -> data){
                swap(temp -> data,temp -> next -> data);
            }
            temp = temp -> next;
        }
    }
    temp = head;
    while(temp -> next) temp = temp -> next;
    tail = temp;
}

int main(){
    create();
    //reverseList();
    sort();
    outPut();
    cout << tail -> data;
    // int t;
    // cin >> t;
    // deleteNum(t);
    // outPut();
    return 0;
}