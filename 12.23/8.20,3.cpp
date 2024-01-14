#include <iostream>

using namespace std;

int a[10000],b[10000];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	for(int i = 100;i >= 0;i--){
		for(int j = 0;j < b[i];j++){
			cout << i << " ";
		}
	}
	return 0;
}
