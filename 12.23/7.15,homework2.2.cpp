#include <iostream>

using namespace std;

int h(int m,int n){
	if(m == 0 || n == 1) return 1;
	if(n > m){
		return h(m,m);
	}
	return h(m,n - 1) + h(m - n,n);
}

int main(){
	int m,n;
	cin >> m >> n;
	cout << h(m,n);
	return 0;
}
