#include <iostream>
#include <cmath> 

using namespace std;



bool is(int n){
	for(int i = 2;i < n;i++){
		if(n % i == 0) return false;
	} 
	return true;
}

int main(){
	int n;
	while(cin >> n && n){
		int sum = 0,k,m = 0;
		int a[101] = {};
		for(int i = 1;i <= n;i++){
			cin >> k;
			sum += ((m - k) > 0 ? (m - k) * 4 : (k - m) * 6) + 5;
			if(is(sum + k)){
				a[k] = 1;
			}
			m = k;
		}
		int f = 0;
		for(int i = 1;i <= 100;i++){
			if(a[i] == 1){
				cout << i << " ";
				f = 1;
			}
		}
		if(!f) cout << "No";
		cout << endl;
	}
	
	
	return 0;
}
