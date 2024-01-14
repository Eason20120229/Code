#include <iostream>

using namespace std;

int index = 0,a[31];

void output(){
	for(int i = 0;i < index;i++){
		cout << a[i] << " "; 
	}
	cout << endl;
}

void up(int n){
	
	if(n == 0){
		output();
		return;
	}
	
	a[index++] = 1;
	up(n - 1);
	index--;
	if(n > 1){
		a[index++] = 2;
		up(n - 2);
		index--;
	}
	if(n > 2){
		a[index++] = 3;
		up(n - 3);
		index--;
	}
}

int main(){
	int n;
	cin >> n;
	while(n > 30 || n < 0){
		cin >> n;
	}
	up(n);
	return 0;
}
