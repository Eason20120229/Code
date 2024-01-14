#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int a[1001],b[1001],c[1001];	//定义变量 

//copy,p ---> q,det,开始
void numcpy(int p[],int q[],int det){
	for(int i = 1;i <= p[0];i++){
		q[i + det - 1] = p[i];
	}
	q[0] = p[0] + det - 1;
}

 
//比较大小 
int compare(int a[],int b[]){
	if(a[0] > b[0]){	//比较长度 
		return 1;
	}
	if(a[0] < b[0]){	//比较长度
		return -1;
	}
	for(int i = a[0];i > 0;i--){	//遍历数组 
		if(a[i] > b[i]){
			return 1;
		}
		if(a[i] < b[i]){
			return -1;
		}
	}
	return 0;
}


//减法计算 a = a - b
void jian(int a[],int b[]){
	int flag;
	flag = compare(a,b);
	if(flag == 0){
		a[0] = 0;
		return;
	}
	if(flag == 1){
		for(int i = 1;i <= a[0];i++){	//运算 
			if(a[i] < b[i]){
				a[i + 1]--;
				a[i] += 10;
			}
			a[i] -= b[i];
		}
		while(a[0] > 0 && a[a[0]] == 0){	//计算长度 
			a[0]--;
		}
		return;
	}
}

//输出 
void print(int a[]){
	if(a[0] == 0){
		cout << 0 << endl;
		return;
	}
	for(int i = a[0];i > 0;i--){
		cout <<a[i];
	}
	cout << endl;
	return;
}

//输入 
void init(int a[]){
	string s;
	cin >> s;
	a[0] = s.length();
	
	for(int i = 1;i <= a[0];i++){	//倒序存储 
		a[i] = s[a[0] - i] - '0';
	}
}

//计算除法a被除数 ---> 余数，b除数，c商 
void chugao(int a[],int b[],int c[]){
	int tmp[1001];
	c[0] = a[0] - b[0] + 1;	//c最大长度 
	for(int i = c[0];i > 0;i--){
		memset(tmp,0,sizeof(tmp));	//重置 
		numcpy(b,tmp,i);	//设置被除数 
		while(compare(a,tmp) >= 0){	//减法 
			c[i]++;
			jian(a,tmp);
		}
	}
	while(c[0] > 0 && c[c[0]] == 0){	//计算长度 
		c[0]--;
	}
	return; 
}
int main(){
	memset(a,0,sizeof(a));	//赋初值为0 
	memset(b,0,sizeof(b));	//赋初值为0
	memset(c,0,sizeof(c));	//赋初值为0
	init(a);	//初始化	
	init(b);	//初始化
	chugao(a,b,c);	//计算 
	print(c);	//输出商 
	print(a);	//输出余数
	return 0;
}
