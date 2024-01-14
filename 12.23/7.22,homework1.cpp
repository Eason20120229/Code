#include<iostream>

using namespace std;

int h(int m,int n){
	if(m % n == 0) return n;
	return h(n,m % n);
}

int main(){
	int m,n;
	cin >> m >> n;
	cout << (m * n) / h(m,n);
	return 0;
}
