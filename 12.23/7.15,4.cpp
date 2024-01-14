#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int a,b;
	double c;
	cin >> a >> b;
	c = sqrt(pow(a,2) + pow(b,2));
	printf("%.2f",c);
	return 0;
}
