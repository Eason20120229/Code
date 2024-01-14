#include<iostream>
#include<cstring>
#include<windows.h>


using namespace std;


int is(int i){
	if(i <= 1){
		return 0;
	}
	for(int j = 2;j < i;j++){
		if(i % j == 0){
			return 0;
		}
	}

	return 1;
	
	
}




int main(){
	int m,n;
	cin >> m >> n;
	
	for(int i = m;i <= n;i++){
		if(is(i)){
			cout << i << endl;
		}
	}
	
	return 0;
}
