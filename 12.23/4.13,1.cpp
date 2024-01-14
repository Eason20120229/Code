#include<iostream>

using namespace std;

int main(){
	char a[100][100];
	int i = 0;
	while(cin >> a[i++]);//循环输入：输入Ctrl + Z结束 
	for(int j = i - 2;j >= 0;j--){
		cout << a[j] << " ";
	}
	return 0;
}
