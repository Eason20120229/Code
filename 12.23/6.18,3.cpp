#include<iostream>

using namespace std;

int main(){
	int n,a[10001] = {},year;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> year;
		a[year - 2000]++;
	}
	int max = a[0]; 
	for(int i = 1;i < 20;i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	for(int i = 0;i < 20;i++){
		if(a[i] == max){
			cout << i + 2000 << endl;
		}
	}
}
