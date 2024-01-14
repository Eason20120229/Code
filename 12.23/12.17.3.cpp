#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(){
	int c = 0;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int last = -1;
	int t = 0;
	for(int i = 0;i < n;i++){
		if(a[i] >= last) {
			t++;
			last = a[i];
		}else{
			t = 1;
			last = a[i];
		}
		c = max(c,t);
	}
	cout << c;
	return 0;
}


