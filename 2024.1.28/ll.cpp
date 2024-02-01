#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;   
};

Node *pre,*temp,*de,*nextNode;

Node *create(){
    Node *tail,*head;
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
    return head;
}

void outPut(Node *head){
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

void deleteNum(Node *head,int c){
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

void headInsert(Node *head,int n){
    temp = new Node;
    if(!head -> next){
        head -> next = temp;
        temp -> data = n;
        temp -> next = nullptr;
        head -> data++;
        return;
    }
    temp -> next = head -> next;
    head -> next = temp;
    temp -> data = n;
    head -> data++;
}

void tailInsert(Node *head,int n){
    Node *temp = head;
    while(temp){
        if(temp -> next == nullptr){
            temp -> next = new Node;
            temp = temp -> next;
            temp -> data = n;
            temp -> next = nullptr;
            head -> data++;
        }
        temp = temp -> next;
    }
}

void insertODUp(Node *head,int n){
    if(!head -> next){
        temp = new Node;
        head -> next = temp;
        temp -> data = n;
        temp -> next = nullptr;
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
        if(!temp -> next) tailInsert(head,n);
        pre = temp;
        temp = temp -> next;
    }
}

void reverseList(Node *head){
    Node *cur = head -> next;
    head -> next = nullptr;
    while(cur){
        nextNode = cur -> next;
        cur -> next = head -> next;
        head -> next = cur;
        cur = nextNode;
    }
}

void sort(Node *head){
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
}

Node *merge(Node *l1,Node *l2){
    Node *head = new Node;
    Node *p = head;
    head -> next = nullptr;
    for(;l1 && l2;p = p -> next){
        if(l1 -> data < l2 -> data){
            p -> next = l1;
            l1 = l1 -> next;
        }else{
            p -> next = l2;
            l2 = l2 -> next;
        }
    }
    p -> next = l1 != nullptr ? l1 : l2; 
    Node *re = head -> next;
    delete head;
    return re;
}

int main(){
    Node *head = create();
    //mergeSort(head);
    outPut(head);
    return 0;
}