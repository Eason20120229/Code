#include <iostream>
#include <cstring>
#include <Windows.h>

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
	char a2[1001] = {};
	int a[1001] = {};
	
	cin >> a2;
	int lena = strlen(a2);
	
	toint2(a2,a);
	
	cout << a[2];
	Sleep(2000);
	system("cls");
	
	return 0;
}
