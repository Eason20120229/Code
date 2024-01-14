#include <iostream>

using namespace std;

void h(int n);

int main(){
	cout << h(5);
	return 0;
}

void h(int n){
	int out[31];
	out[0] = 1;
	out[1] = 2;
	out[2] = 3;
	if(n == 1){
		cout << 1;
	}else{
		h(n - 1);
	}
}
