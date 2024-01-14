#include <iostream>

using namespace std;

int flag = 1;

int f(int m,int n){
	if(n == 0){
		return 1;
	}
	return f(m,n - 1) * (m + 1);
}

int main(){
	int m,n;
	cin >> m >> n;
	cout << f(m,n);
	return 0;
}
