#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	m *= 2;
	for(int i = 1;i < n;i++){
		m = (m - 2) * 2;
	}
	cout << m;
	return 0;
}
