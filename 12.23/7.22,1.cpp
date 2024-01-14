#include <iostream>

using namespace std;

int step = 0;

void f(int n){
	cout << n << " ";
	if(n == 1) return;
	if(n % 2 == 0){
		f(n / 2);
	}else{
		f(n * 3 + 1);
	}
	step++;
}

int main(){
	int n;
	cin >> n;
	f(n);
	cout << endl << "STEP=" << step;
	return 0;
}
