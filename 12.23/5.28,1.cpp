#include <iostream>

using namespace std;

int age(int age);

int main(){
	cout << age(5);
	return 0;
}

int age(int n){
	if(n == 1){
		return 10;
	}
	return age(n - 1) + 2;
}
