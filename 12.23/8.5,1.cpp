#include <iostream>

using namespace std;

int main(){
	int a[102] = {0,1,2,3,4},n;
	cin >> n;
	for(int i = 5;i <= n;i++){
		a[i] = a[i - 1] + a[i - 3];
	}
	cout << a[n] - 1;
	return 0;
}
