#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double h(double x,int n){
	if(n == 1){
		return sqrt(n + x);
	}
	return sqrt(n + h(x,n - 1));
}

int main(){
	double x;
	int n;
	scanf("%lf %d",&x,&n);
	printf("%.2lf",h(x,n));
	return 0;
}
