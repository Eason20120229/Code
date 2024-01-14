#include<iostream>

using namespace std;

int main(){
	for(int i = 0;i <= 28;i++){
		for(int j = 0;j <= 28;j++){
			int z = 30 - i - j;
			if(i * 30 + j * 20 + z * 10 == 500){
				cout << i << "	" << j << "	" << z << endl;
			}
		}
	}
	return 0;
}
