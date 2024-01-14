#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> l;
    list<int> :: iterator i;
    for(int i = 1;i <= 3;i++){
        l.push_front(i);
    }
    for(int i = 4;i <= 6;i++){
        l.push_back(i);
    }
    cout << "-------------" << endl;
    for(i = l.begin();i != l.end();i++){
        cout << *i << " ";
    }
    return 0;
}