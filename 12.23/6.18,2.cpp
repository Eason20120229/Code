#include<iostream>

using namespace std;
int a[20];
int main(){
	int s,n,sum = 0;
	cin >> n;
	
	for(int i = 0;i < n;i++){
		s = i % 3 + 1;
		cin >> a[i];
		a[i] *= s;
		sum += a[i];
	}
	cout << sum;
}
