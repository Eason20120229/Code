#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *temp,*pre,*nextNode,*de;

Node *listInit(){
    Node *head;
    head = temp = new Node;
    head -> next = nullptr;
    int n,cnt = 0;
    cin >> n;
    while(n != 0){
        cnt++;
        temp -> next = new Node;
        temp = temp -> next;
        temp -> next = nullptr;
        temp -> data = n;
        cin >> n;
    }
    head -> data = cnt;
    temp = nullptr;
    return head;
}

void output(Node *head){
    if(!head -> next){
        cout << "The list is empty." << endl;
        return;
    }
    temp = head -> next;
    cout << "The list has " << head -> data
         << " numbers."<< endl;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(Node *head,int c){
    int cnt = 0;
    if(head -> next){
        pre = head;
        temp = head -> next;
        while(temp){
            if(temp -> data == c){
                pre -> next = temp -> next;
                de = temp;
                temp = temp -> next;
                delete de;
                cnt++;
                continue;
            }
            pre = temp;
            temp = temp -> next;
        }
        head -> data -= cnt;
    }else{
        cout << "The list is empty." << endl;
    }
}

void tailInsert(Node *head,int m){
    temp = head;
    while(temp -> next) temp = temp -> next;
    temp -> next = new Node;
    temp = temp -> next;
    temp -> data = m;
    temp -> next = nullptr;
}

void headInsert(Node *head,int m){
    temp = new Node;
    temp -> data = m;
    temp -> next = head -> next;
    head -> next = temp;
}

void insertODUp(Node *head,int m){
    if(!head -> next){
        temp = new Node;
        head -> next = temp;
        temp -> data = m;
        temp -> next = nullptr;
        return;
    }
    pre = head;
    while(pre -> next){
        if(pre -> next -> data > m){
            temp = new Node;
            temp -> next = pre -> next;
            temp -> data = m;
            pre -> next = temp;
            return;
        }
    }
    temp = new Node;
    pre -> next = temp;
    temp -> next = nullptr;
    temp -> data = m;
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

Node *mSort(Node *head){
    if(!head || !head -> next) return head;
    Node *fast = head,*slow = head;
    while(fast -> next && fast -> next -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    fast = slow;
    slow = slow -> next;
    fast -> next = nullptr;
    Node *l1 = mSort(head),*l2 = mSort(slow);
    return merge(l1,l2);
}

void mergeSort(Node *head){
    head -> next = mSort(head -> next);
}

int main(){
    Node *head = listInit();
    output(head);
    mergeSort(head);
    output(head);
    return 0;
}