#include <iostream>

using namespace std;

int main(){
	string s;
	char c;
	cin >> s;
	int len = s.length();
	for(int i = len - 1;i >= 0;i--){
		if(s[i] > 'a' && s[i] < 'z'){
			c = s[i] - 32 + 3;
			if(c > 'Z'){
				c -= 26;
			}
			cout << c;
		}else{
			c = s[i] + 32 + 3;
			
			if(c > 'z'){
				c -= 26;
			}
			
			cout << c;
		}
	}
	return 0;
}

