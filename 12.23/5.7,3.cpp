#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

void zhi(int a[],int b[],int h){
	for(int i = 0;i < h;i++){
		a[i] = b[i];
	}
} 

void toint2(char a[],int b[]){
	for(int i = 0;i < strlen(a);i++){
		b[strlen(a) - i] = a[i] - 48;
	}
}

void outint2(int a[],int h){
	int t = 0;
	for(int i = h - 1;i > 0;i--){
		if(a[i] != 0 || t == 1){
			t = 1;
			cout << a[i];
		}
		
	}
	if(t == 0){
		cout << 0;
	} 
}

int jia(int a[],int b[],int c[],int h){
	int he,i,j = 0;
	for(i = 1;i < h;i++){
		he = a[i] + b[i] + j;
		if(he >= 10){
			he = he % 10;
			j = 1;
			c[i] = he;
		}else{
			j = 0;
			c[i] = he;
		}
	}
	c[i] = j;
	if(j == 1){
		return h + 1;
	}else{
		return h;
	}
}

int jian(int a[],int b[],int c[],int h,int h2){
	int cha = 0,j = 0;	//cha����ÿһ�εĲ�,j�����λ 
	char c1[h] = {},c2[h] = {};
	
	for(int i = 0;i < h;i++){
		c1[i] = a[h - i] + 48;
	}
	for(int i = 0;i < h2;i++){
		c2[i] = b[h2 - i] + 48;
	}
	
	if(h < h2 || h == h2 && strcmp(c1,c2) == -1){	//����С 
		swap(a,b);
		cout << "-";
	}
	
	for(int i = 1;i <= (h > h2 ? h : h2);i++){	//���� 
		cha = a[i] - b[i] + j;
		if(cha < 0){	//���cha�Ƿ�С����,�ǵĻ�,cha+10,���ý�λ�� 
			cha = cha + 10;
			j = -1;
			c[i] = cha;
		}else{	//���λ��0 
			j = 0;
			c[i] = cha;
		}
	}
	int k;
	for(k = (h > h2 ? h : h2); k>0; k--){
		if(c[k] != 0){
	 		break;
		} 
	}
	return k;
}

int cheng (int a[],int b[],int c[],int h,int h2){
	int x = 0;	//�����λ 
	for(int i = 1;i <= h;i++){	//Ƕ��ѭ���˷���ʽһ���� 
		for(int j = 1;j <= h2;j++){
			c[i + j - 1] += a[i] * b[j] + x;	//�ѻ��浽��Ӧλ 
			x = c[i + j - 1] / 10;	//�����λ 
			c[i + j - 1] %= 10;	//�����λ 
		}
		c[i + h2] = x; //��λ 
	}
	
	int k;
	for(k = h + h2; k>0; k--){
		if(c[k] != 0){
	 		break;
		} 
	}
	return k;
}



int main(){
	
	return 0;
}
