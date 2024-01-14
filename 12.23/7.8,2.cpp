#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int max = 0,p1 = 0,first = 1;
	cin >> s;
	for(int i = 1;i < s.length();i++){
		if(s[i] == '#' && first){
			first = 0;
			p1 = i;
		}else if(!first && s[i] != '#'){
			first = 1;
			if(i - p1 > max) max = i - p1;
		}
	}
	cout << max;
	return 0;
}
