#include<iostream>

using namespace std;

float money(){
	int a,i = 0,h;
	float money;
	cin >> h;
	while(i < h){
		cin >> a;
		
		if(a % 70 == 0){
			money += (a / 70) * 0.1;
		}else{
			money += (a / 71 + 1 ) * 0.1;
		}
		i++;
	}
	return money;
}


int main(){
	
	cout << money() << endl;
	return 0;
}
