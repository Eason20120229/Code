#include<iostream>

using namespace std;

int main(){
	int m,n,s,a,b;
	cin >> n >> m;
	int c[n] = {};
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		for(int j = a;j <= b;j++){
			c[j] = 1;
		}
	}
	for(int i = 0;i < n;i++){
		if(c[i] == 0){
			s++;
		}
	}
	cout << s;
}
