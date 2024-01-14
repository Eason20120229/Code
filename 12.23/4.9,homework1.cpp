#include<iostream>

using namespace std;

int money(int day){
	int money;
	int j = 1,o = 0;
	for(int i = 1;;i++){
		for(int h = 0;h < i;h++){
			money += j;
			o++;
			if(o>=day){
				return money;
			}
		}
		j++;	
	}
	
}


int main(){
	int day;
	
	cin >> day;
	cout << money(day) << endl;
	return 0;
}
