#include <iostream>
#include <cstring>

using namespace std;

void toint2(char a[],int b[]){
	for(int i = 0;i < strlen(a);i++){
		b[strlen(a) - i - 1] = a[i] - 48;
	}
}

void outint(int a[],int h){
	for(int i = 0;i < h;i++){
		cout << a[i];
	}
}

int main(){
	char a2[1001] = {},b2[1001] = {};
	int a[1001] = {},b[1001] = {};
	
	cin >> a2 >> b2;
	int lena = strlen(a2);
	int lenb = strlen(b2);
	
	toint2(a2,a);
	toint2(b2,b);
	outint(a,lena);
	cout << "\n";
	outint(b,lenb);
	
	return 0;
}
