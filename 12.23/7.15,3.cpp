#include <iostream>
using namespace std;
void h(string s,int c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		for(int i = 0;i < s.length();i++) {
			if(s[i] != c) cout << s[i];
		}
	}else{
		for(int i = 0;i < s.length();i++) {
			if(s[i] != ' ') cout << s[i];
		}
	}
}
int main(){
	string str;
	char c;
	getline(cin,str);
	cin >> c;
	h(str,c);
	return 0;
}
