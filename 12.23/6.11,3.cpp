#include<iostream>

using namespace std;

int main(){
	int n;
	for(int i = 2;i <= 1000;i++){
		n = 0;
		for(int j = 1;j < i;j++){
			if(i % j == 0){
				n += j;
			}
		}
		if(i == n){
			cout << i << endl;
		}
	}
}
