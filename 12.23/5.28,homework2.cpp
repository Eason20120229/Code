#include <iostream>

using namespace std;

void h(int s,int n){
	static int a[1001];
	if(n == 1){
		cout << a[1];
		for(int i = 2;i <= s - 1;i++){
			cout << " * " << a[i];
		}
		cout << endl;
		return;
	}
	for(int i = 2;i <= n;i++){
		if(n % i == 0){
			a[s] = i;
			h(s + 1,n / i);
			return;
		}
	}
}

int main(){
	int n;
	cin >> n;
	while(n > 2147483647 || n < 0){
		cin >> n;
	}
	cout << n << " = ";
	h(1,n);
	
	return 0;
}
