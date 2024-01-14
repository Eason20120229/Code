#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	double m,n;
	double time;
	scanf("%lf %lf",&m,&n);
	if(m >= n){
		printf("нч╫Б"); 
	}
	
	time = 1 / ((1 / m) - (1 / n));
	printf("%lf",time);
	return 0;
}
