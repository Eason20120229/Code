#include<iostream>

using namespace std;

int main(){
	int a[10];
	for(int i = 0;i < 10;i++){
		cin >> a[i];
	}
	for(int i = 0;i < 10;i += 2){
		a[i] = (a[i] + 5) % 10;
		a[i + 1] = (a[i + 1] + 5) % 10;
		cout << a[i + 1] << " " << a[i] << " ";
	}
}
