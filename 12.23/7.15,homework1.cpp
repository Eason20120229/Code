#include <iostream>
#include <string> 

using namespace std;

int main(){
	string str;
	char c;
	getline(cin,str);
	int i,n = -1,len = str.length();
	cin >> c >> i;
	if(i < 0){
		for(int j = len - 1;j >= 0;j--){
			if(str[j] == c) {
				n = j;
				break;
			}
		}
	}else{
		for(int j = i - 1;j < len;j++){
			if(str[j] == c) {
				n = j;
				break;
			}
		}
	}
	cout << n;
	return 0;
}
