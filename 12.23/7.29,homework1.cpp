#include <iostream>

using namespace std;

int main(){
	int a[10] = {0,1,1},b;
	cin >> b;
	for(int i = 3;i <= 17;i++){
		a[i] = a[i - 1] + a[i - 2];
		if(a[i] == b){
			cout << i;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
