#include <iostream>

using namespace std;


int a[100000],n,b;

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> b;
		a[b]++;
	}
	
	for(int i = 0;i <= 100;i++){
		for(int j = 0;j < a[i];j++){
			cout << i << " ";
		}
	}
	
	return 0;
}
