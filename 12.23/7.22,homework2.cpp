#include <iostream>

using namespace std;

void h(int n,int m){
	if(n == 0){
		cout << "共有" << m << "只鸭子\n";
		return; 
	}
	h(n - 1,(m + 1) * 2);
	cout << "到第" << n << "个村庄有" << m << "只鸭子\n";
}

int main(){
	h(7,2);
}
