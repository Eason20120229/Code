#include <iostream>

using namespace std;

int a[1000][1000];

int main(){
	int n,s;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			cin >> a[i][j];
		} 
	}
	
	for(int i = n;i > 1;i--){
		for(int j = 1;j <= i;j++){
			a[i - 1][j] = a[i - 1][j] + 
				(a[i][j] > a[i][j + 1] ? 
				a[i][j] : a[i][j + 1]);
		} 
	}
	cout << a[1][1];
	return 0;
}
