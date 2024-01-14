#include<iostream>
#include<cmath>

using namespace std;

int a[1000][1000];

int main(){
	int n;
	cin >> n;
	for(int k = 1;k <= n;k++){
		for(int i = k;i <= n * 2 - k;i++){
			for(int j = k;j <= n * 2 - k;j++){
				a[i][j] = k;
			}
		}
	}
	for(int i = 1;i <= n * 2 - 1;i++){
		for(int j = 1;j <= n * 2 - 1;j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
} 
