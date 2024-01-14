#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(){
	int c;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		int t = 0;
		int last = -1;
		for(int j = i;j < n;j++){
			if(last <= a[j]){
				t++;
				last = a[j];
			}
		}
		c = max(c,t);
	}
	cout << c;
	return 0;
}


