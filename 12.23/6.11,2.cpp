#include<iostream>

using namespace std;

int main(){
	int n,k,p;
	cin >> n;
	long long sm;
	while(n){
		k = n;
		p = 1;
		while(k){
			p *= k;
			k--;
		}
		sm += p;
		n--;
	}
	cout << sm;
	return 0;
}
