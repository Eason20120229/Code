#include<iostream>
#include<cstring>
using namespace std;
char a1[1001];
int a[1001],c[1001];
int main(){
	int b,lena,lenc,x=0;
	cin >> a1 >> b;
	lena = strlen(a1);	//a���鳤�� 
	for(int i=0;i<lena;i++){	//����洢 
		a[i+1] = a1[i] - 48;
	}
	for(int i=1;i<=lena;i++){	//��������
		c[i] = (x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	lenc=1;	//c�ĳ��� 
	while(c[lenc]==0&&lenc<lena){	//����c�ĳ��� 
		lenc++;
	}
	for(int i=lenc;i<=lena;i++){	//��� 
		cout<<c[i];
	}	
	return 0;
}
