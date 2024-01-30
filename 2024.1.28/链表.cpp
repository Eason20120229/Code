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
    Node *head;
    MyList(){
        head = new Node;
        head -> data = 0;
        head -> next = nullptr;
    }
    MyList(int a[], int n){
        Node *tail;
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

    void headInsert(int n){
        Node *pre = head;
        Node *temp = head -> next;
        pre -> next = new Node;
        pre = pre -> next;
        pre -> next = temp;
        pre -> data = n;
        head -> data++;
    }
};

int main()
{
    int n;
    cin >> n;
    int a[1001] = {};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    MyList l(a, n);
    l.outPut();
    int t;
    cin >> t;
    l.deleteNum(t);
    l.outPut();
    int he,ta;
    cin >> he;
    l.headInsert(he);
    l.outPut();
    cin >> ta;
    l.tailInsert(ta);
    l.outPut();
    return 0;
}