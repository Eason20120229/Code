#include<iostream>
#include<cstring>

using namespace std;

int set(int a[],int len){
	for(int i = 0;i < len;i++){
		a[i] = 0;
	}
}

int main(){
	int a[6] = {23,123,231,45,231,354};
	for(int i = 0;i < 6;i++){
		cout << a[i] << endl;
	}	
	set(a,6);
	cout << endl << endl;
	for(int i = 0;i < 6;i++){
		cout << a[i] << endl;
	}
	return 0;
}



