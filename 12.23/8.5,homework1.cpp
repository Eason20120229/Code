#include <iostream>
#include <cstring>

using namespace std;

//쳲��������е�n����� 
int f(int x){
	if(x == 0) return 0;
	if(x == 1 || x == 2) return 1;
	return f(x - 1) + f(x - 2);
}

int main(){
	int a,n,b,x,m,sum;	 //m ->�ڶ�վ�ϳ����� ��sum����� 
	cin >> a >> n >> b >> x;
	if(x == 1 || x == 2) cout << a;	// ��һ����վ��ֱ�����a�� 
	else{
		/* 
		f(3-2)-f(3-3)+f(4-2)-f(4-3)+ ... +
		f(n-2)-f(n-3)=(f(n - 3) + 1))�� 
		*/ 
		//(f(n - 2) - 1)�� (f(x - 2) + 1)�� (f(x - 1) - 1)�Դ����ơ� 
		m = (b - a * (f(n - 3) + 1)) / (f(n - 2) - 1);	
		sum = a * (f(x - 2) + 1) + m * (f(x - 1) - 1);
		cout << sum;	//�������� 
	}
	return 0;
}
