#include<iostream>
#include<cstring>
using namespace std;

void s(int &a){
	a = 10;
}

int main(){
	int a = 20;
	cout << a << endl;
	s(a);
	cout << a << endl;
	return 0;
}

