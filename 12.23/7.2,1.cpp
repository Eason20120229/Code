#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	int l = s.length();
	for(int i = 0;i < l;i++){
		int k;
		for(int j = 0;j < l;j++){
			if(s[i] == s[j] && i != j){
				k = 1;
			}
		}
		if(k == 0){
			cout << i + 1;
			return 0;
		}
	}
	cout << "no";
	return 0;
}




//
//char str[40];
//cin >> str;
//int count[256] = {};
//int n = 0;
//while(str[n] != '\0'){
//	count[str[n]]++;
//	n++;
//}
//n = 0;
//while(str[n] != '\0'){
//	if(count[str[n]] == 1){
//		cout << n + 1;
//		return 0;
//	}
//	n++;
//}
//cout << "no";

