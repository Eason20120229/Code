#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int a[6] = {},n;
	for(int j = 1;j < 10000;j++){
		memset(a,0,5);
		a[0] = j;
		if(a[0] % 4 != 0) continue;
		for(int i = 1;i < 6;i++){
			if(a[i - 1] % 4 != 0) break;
			a[i] = a[i - 1] / 4 * 5 + 1;
		}
		if(a[5] != 0) break;
	}
	cout << a[5];
	return 0;
}
