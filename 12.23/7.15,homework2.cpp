#include <iostream>

using namespace std;

int sum = 0;

void ball(int m,int n,int last){
	if(m == 0 && n >= 0) sum++;
	if(m <= 0 || n <= 0) return;
	for(int i = last;i <= m;i++) ball(m - i,n - 1,i);
}

int main(){
	int m,n;
	cin >> m >> n;
	ball(m,n,1);
	cout << sum;
	return 0;
}
