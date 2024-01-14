#include <iostream>
#include <cstring>

using namespace std;

char s[10000] = {},c[5] = {'h','a','p','p','y'},i = 0;

int main(){
	cin >> s;
	for(int j = 0;j < strlen(s) && i < 5;j++){
		if(s[j] == c[i]){
			i++;
		}
	}
	if(i == 5){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
