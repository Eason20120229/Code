#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s;
	int len = 0,max = 0,first = 1;
	cin >> s;
	for(int i = 1;i < s.length();i++){
		if(s[i] == '#'){
			if(first){
				first = 0;
				len = 0;
			}
			len++;
		}else{
			first = 1;
			if(len > max) max = len;
		}
	}
	cout << max;
	return 0;
}
