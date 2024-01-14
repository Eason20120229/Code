#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[1001] = {};
	a[0] = a[1] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 0;j < i;j++){
			a[i] += a[j] * a[i - 1 - j];
		}
	}
	cout << a[n];
	return 0;
}


