#include<iostream>
#include<cstring>
#include<windows.h>


using namespace std;

int x = 10,y = 50;

void test(){
	int x = 30;
	cout << "test:" << x << endl;
	cout << "test:" << y << endl;
}

int main(){
	test();
	cout << "main:" << x << endl;
	cout << "main:" << y << endl;
	return 0;
}
