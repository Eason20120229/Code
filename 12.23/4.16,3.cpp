#include<iostream>
#include<cstring>
#include<cstdio>


using namespace std;


int main(){
	int a;
	double b;
	char c;
	scanf("%d",&a);
	scanf("%lf %c",&b,&c);
	printf("%d\n",a);
	printf("%.2lf",b);
	printf("\n%c",c);
	return 0;
}
