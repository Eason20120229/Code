#include <iostream>
#include <cstring>

using namespace std;

//斐波那契数列第n项函数。 
int f(int x){
	if(x == 0) return 0;
	if(x == 1 || x == 2) return 1;
	return f(x - 1) + f(x - 2);
}

int main(){
	int a,n,b,x,m,sum;	 //m ->第二站上车的人 ，sum结果。 
	cin >> a >> n >> b >> x;
	if(x == 1 || x == 2) cout << a;	// 第一、二站，直接输出a。 
	else{
		/* 
		f(3-2)-f(3-3)+f(4-2)-f(4-3)+ ... +
		f(n-2)-f(n-3)=(f(n - 3) + 1))。 
		*/ 
		//(f(n - 2) - 1)、 (f(x - 2) + 1)、 (f(x - 1) - 1)以此类推。 
		m = (b - a * (f(n - 3) + 1)) / (f(n - 2) - 1);	
		sum = a * (f(x - 2) + 1) + m * (f(x - 1) - 1);
		cout << sum;	//输出结果。 
	}
	return 0;
}
