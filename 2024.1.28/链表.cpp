#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 创建节点
struct Node{
    int data;
    Node *next;
};

class MyList{

public:
    Node *head,*tail;
    MyList(){
        tail = head = new Node;
        head -> data = 0;
        head -> next = nullptr;
    }
    MyList(int a[], int n){
        tail = head = new Node;
        head -> next = nullptr;
        for (int i = 0; i < n; i++){
            Node *temp = new Node;
            temp -> data = a[i];
            tail -> next = temp;
            tail = temp;
            tail -> next = nullptr;
        }
        head -> data = n;
    }

    void outPut(){
        Node *temp;
        if (head -> next)
            temp = head -> next;
        else{
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
    }

    void deleteNum(int c){
        Node *pre = nullptr,*temp = nullptr,*de = nullptr;
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

    void tailInsert(int n){
        // Node *temp = head;
        // while(temp){
        //     if(temp -> next == nullptr){
        //         temp -> next = new Node;
        //         temp = temp -> next;
        //         temp -> data = n;
        //         temp -> next = nullptr;
        //         head -> data++;
        //     }
        //     temp = temp -> next;
        // }
        tail-> next = new Node;
        tail = tail -> next;
        tail -> next = nullptr;
        tail -> data = n;
    }

    void headInsert(int n){
        if(!head -> next){
            Node *t = new Node;
            t -> data = n;
            t -> next = nullptr;
            head -> next = t;
            head -> data++;
            tail = t;
            return;
        }
        Node *temp = new Node;
        temp -> data = n;
        temp -> next = head -> next;
        head -> next = temp;
        head -> data++;
    }

    void insertODUp(int n){
        Node *temp = head,*pre;
        if(!head -> next){
            Node *t = new Node;
            t -> data = n;
            t -> next = nullptr;
            head -> next = t;
            head -> data++;
            tail = t;
            return;
        }
        temp = head -> next;
        pre = head;
        while(temp){
            if(temp -> data > n){
                if(temp == head -> next) headInsert(n);
                else{
                    Node *t = new Node;
                    t -> data = n;
                    t -> next = pre -> next;
                    pre -> next = t;
                    head -> data++;
                }
                return;
            }
            if(temp -> next == nullptr){
                tailInsert(n);
                return;
            }
            pre = temp;
            temp = temp -> next;
        }
    }

    void reverseList(){
        Node *nextNode;
        Node *cur = head -> next;
        head -> next = nullptr;
        tail = cur;
        while(cur){
            nextNode = cur -> next;
            cur -> next = head -> next;
            head -> next = cur;
            cur = nextNode;
        }
    }

    void sort(){
        int i,j;
        for(i = head -> data;i > 0;i--){
            Node *temp = head -> next;
            for(j = 1;j < i;j++){
                if((temp -> data) > (temp -> next -> data)){
                    swap(temp -> data,temp -> next -> data);
                }
                temp = temp -> next;
            }
        }
        Node *temp = head;
        while(temp -> next) temp = temp -> next;
        tail = temp;
    }

};

int main(){
    int n;
    cin >> n;
    int a[1001] = {};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    MyList l(a, n);
    l.outPut();
    // int t;
    // cin >> t;
    // l.deleteNum(t);
    // l.outPut();
    // int he,ta;
    // cin >> he;
    // l.headInsert(he);
    // l.outPut();
    // cin >> ta;
    // l.tailInsert(ta);
    // l.outPut();
    // int u;
    // cin >> u;
    // l.insertODUp(u);
    l.reverseList();
    // l.sort();
    l.outPut();
    return 0;
}