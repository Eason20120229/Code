#include <iostream>

using namespace std;

void rd(int a[],int i,int k){
	int j,p;
	for(int j = i;j >=1;j--){ //3 
		if(j <= a[k - 1]){
			a[k] = j;
			if(j == i){
				cout << a[0] << "=" << a[1];
				for(int p = 2;p <= k;p++){
					cout << "+" << a[p];
				}
				cout << endl;
			}else{
				rd(a,i - j,k + 1);
			}
		}
	}
}

int main(){
	int a[100000] = {},i;
	cin >> i;
	a[0] = i;
	rd(a,i,1);
	return 0;
}
