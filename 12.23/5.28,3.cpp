#include <iostream>

using namespace std;

int rabbit(int n);

int main(){
	int a;
	cin >> a;
	for(int i = 1;i <= a;i++){
		cout << rabbit(i) << "	";
	}
	
	return 0;
}

int rabbit(int n){
	if(n <= 2){
		return 1;
	}
	return rabbit(n - 1) + rabbit(n - 2);
}
