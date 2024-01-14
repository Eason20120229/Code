#include <bits/stdc++.h> 

using namespace std;

void f(string s){
	string ss = "";
	for(int i = 1;i < s.length();i++){
		if((i + 1) % 2 == 0){
			cout << s[i];
		}else{
			ss = s[i] + ss;
		}
	}
	if(s.length() > 0) f(ss);
}

int main(){
	string s;
	cin >> s;
	f(s);
	return 0;
}
