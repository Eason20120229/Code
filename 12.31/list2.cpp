#include<bits/stdc++.h>
using namespace std;

typedef list<int> li;

void put(li l1,string n){
    cout << n << ":";
    li :: iterator i;
    for(i = l1.begin();i != l1.end();i++){
        cout << *i << " ";
    }
    cout << endl;
}

int main(){
    li l1;
    li l2(5,1);
    li l3(l2.begin(),--l2.end());
    put(l1,"l1");
    put(l2,"l2");
    put(l3,"l3");
    l1.push_back(7);
    l1.push_back(8);
    put(l1,"l1");
    l1.push_front(6);
    l1.push_front(5);
    put(l1,"l1");
    l1.insert(++l1.begin(),3,9);
    put(l1,"l1");
    l1.pop_front();
    l1.pop_back();
    put(l1,"l1");
    l2.assign(8,1);
    put(l2,"l2");
    cout << "1 > 3:" << (l1 > l3) << endl;
    l1.push_front(12);
    l1.sort();
    put(l1,"l1");
    return 0;
}