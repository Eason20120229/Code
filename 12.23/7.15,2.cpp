#include <iostream>
using namespace std;
void h(string a,int s,int n,int len){
	string b = "";
	if(s == 1){
		for(int i = 0;i < n;i++){
			cout << a[i];
		}
	}else{
		for(int i = 0;i < len;i++){
			b[len - i - 1] = a[i];
		}
		for(int i = 0;i < 100;i++){
			cout << (int)b[i] << endl;
		}
		cout << b;
	}
}
int main(){
	int n = 0,s;
	string str;
	cin >> s;
	cin >> str;
	if(s == 1)cin >> n;
	int len = str.length();
	h(str,s,n,len);
	return 0;
}
