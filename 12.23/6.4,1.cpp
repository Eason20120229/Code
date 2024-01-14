#include <iostream>

using namespace std;

int main(){
	int n,m = 1;
	cin >> n;
	for(int i = 0;i < n;i++){
		m = m * 2 + 1;
	}
	cout << m;
	return 0;
}
