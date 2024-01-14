#include<iostream>

using namespace std;

int main(){
	int n = 0;
	for(int i = 0;i <= 20;i++){
		for(int j = 0;j <= 4;i++){
			for(int h = 0;h <= 2;i++){
				if(i + j * 5 + h * 10 == 20){
					n++;
				}
			}
		}
	}
	cout << n;
}
