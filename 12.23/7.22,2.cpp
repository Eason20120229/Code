#include <iostream>
#include <string>

using namespace std;

string c = "";

void h(int n,int m){
	if(n == 0){
		return;
	}
	h(n / m,m);
	if(n % m >= 10){
		cout << char(n % m - 10 + 'A');
		return;
	}
	cout << n % m;
	return;
}

int main(){
	long long n,m;
	
	cin >> n >> m;
	h(n,m);
	return 0;
}
