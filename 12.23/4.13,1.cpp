#include<iostream>

using namespace std;

int main(){
	char a[100][100];
	int i = 0;
	while(cin >> a[i++]);//ѭ�����룺����Ctrl + Z���� 
	for(int j = i - 2;j >= 0;j--){
		cout << a[j] << " ";
	}
	return 0;
}
