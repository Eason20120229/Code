#include <iostream>
#include <cstring>
#include <string>
#include "8.26,2.h"

using namespace std;

void bt(int l1,int r1,int l2,int r2);

string s1,s2;

void bt(int l1,int r1,int l2,int r2){
    int m = s2.find(s1[l1]);
    if(m > l2) bt(l1 + 1,l1 + m -l2,l2,m - 1);
    if(m < r2) bt(l1 + m - l2 + 1,r1,m + 1,r2);
    cout << s1[l1];
}

int main(){
    btnd data[1000];
    cin >> s1 >> s2;
    bt(0,s1.length() - 1,0,s2.length() - 1);
    return 0;
}

