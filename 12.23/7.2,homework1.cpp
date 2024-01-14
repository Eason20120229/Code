#include <iostream>
#include <cstdio>

using namespace std;

string s;

int main(){
	int n,flags[100];
	char a,b;
	
	do{
		cin >> n;
	}while(n < 1 || n > 100);
	
	for(int i = 0;i < n;i++){
		s = "";
		cin >> a >> s;
		s = "";
		cin >> b >> s;
		if(b == a) {
			flags[i] = 0;
			continue;
		}
		else if(a == 'R' && b == 'P')
			flags[i] = 2;
		else if(a == 'S' && b == 'R')
			flags[i] = 2;
		else if(a == 'P' && b == 'S')
			flags[i] = 2;
		else flags[i] = 1;
	}
	for(int i = 0;i < n;i++){
		cout << flags[i] << endl;
	}
	
	return 0;
}
