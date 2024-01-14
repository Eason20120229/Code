#include<iostream>
#include<cstring>
using namespace std;
char a1[1001];
int a[1001],c[1001];
int main(){
	int b,lena,lenc,x=0;
	cin >> a1 >> b;
	lena = strlen(a1);	//a数组长度 
	for(int i=0;i<lena;i++){	//正序存储 
		a[i+1] = a1[i] - 48;
	}
	for(int i=1;i<=lena;i++){	//除法计算
		c[i] = (x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	lenc=1;	//c的长度 
	while(c[lenc]==0&&lenc<lena){	//计算c的长度 
		lenc++;
	}
	for(int i=lenc;i<=lena;i++){	//输出 
		cout<<c[i];
	}	
	return 0;
}
