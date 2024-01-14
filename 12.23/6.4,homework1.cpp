#include<iostream>

using namespace std;

int main(){
	double money[52] = {0.0};
	int n;
	do{
		cin >> n;
	}while(n < 0 || n > 50);
	
	while(n > 0){
		money[n] = (money[n + 1] + 1000) / (0.0031 * 12 + 1);
		n--;
	}
	cout << money[1];
	return 0;
}
