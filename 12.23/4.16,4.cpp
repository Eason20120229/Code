#include<iostream>
#include<cstring>
#include<windows.h>


using namespace std;

long long is[10000001];


int main(){
	int n;
	cin >> n;
	for(int i = 0;i < 10000001;i++){
		is[i] = 1;
	}
	for(int i = 2;i <= n;i++){
		if(is[i] == 1){
			for(int j = i * 2;j <= n;j += i){
				is[j] = 0;
			}
		}
	}
	
	for(int i = 2;i <= n;i++){
		if(is[i] == 1){
			cout << i << endl;
		}
	}

	return 0;
}
