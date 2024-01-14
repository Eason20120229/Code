#include <bits/stdc++.h>

using namespace std;

long long c[1000000];

int main(){
	int a,n;
	while(cin >> a){
		cin >> n;
		int i = 1,i1 = 0,i2 = 0;
		c[0] = a;
		while(i < n){
			if(c[i1] * 2 + 1 > c[i2] * 3 + 1){
				c[i] = c[i2] * 3 + 1;
				i2++;
			}else{
				c[i] = c[i2] * 2 + 1;
				i1++;
			}
			if(c[i] == c[i - 1]){
				c[i] = 0;
				continue;
			}
			i++;
		}
		cout << c[n - 1] << endl;
	}
	return 0;
}
