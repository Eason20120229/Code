#include <iostream>

using namespace std;

//int f(int n){
//	if(n == 1) return 0;
//	if(n == 2) return 1;
//	return (f(n - 2) + f(n - 1)) * (n - 1);
//}

int main(){
	int n;
	//int s = 1;
	cin >> n;
	//cout << f(n);
	int a[101] = {0,1};
	for(int i = 0;i <= n;i++){
		a[i] = (i - 1) * (a[i - 2] + a[i - 1]);
	}
	cout << a[n];
	return 0;
}
