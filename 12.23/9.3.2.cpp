#include <iostream>
#include <cstring>
#include <string>
#include "8.26,2.h"
#include <cstdio>

using namespace std;

void bt(int l1,int r1,int l2,int r2);

string s1,s2;

/*
DBEAC
ABCDE



ABDEC
*/

void bt(int l1,int r1,int l2,int r2){
    int j;
    for(int i = l2;i <= r2;i++){
    	int f = 0;
    	for(j = l1;j <= r1;j++){
    		if(s2[i] == s1[j]){
    			cout << s1[j];
    			f = 1;
    			break;
			}
		}
		if(f) break;
	}
	if(j > l1) bt(l1,j - 1,0,r2);
	if(j < r1) bt(j + 1,r1,0,r2);
}

int main(){
    cin >> s1 >> s2;
    bt(0,s1.length() - 1,0,s2.length() - 1);
    return 0;
}

