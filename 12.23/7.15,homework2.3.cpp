#include <iostream>

using namespace std;

int h(int m,int n){
	if(m < n) return 0;
	if(n == 1) return 1;
	return h(m - 1,n - 1) + h(m - 1,n) * n;
}

int main(){
	int m,n;
	cin >> m >> n;
	cout << h(m,n);
	return 0;
}
