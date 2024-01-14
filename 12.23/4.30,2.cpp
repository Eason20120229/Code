#include <iostream>

using namespace std;

struct Monkey{
	int name;
	int shu;
};

int main(){
	int n,max;
	Monkey mon[100];
	
	cin >> n;
	
	while(n > 100 && n < 2){
		cin >> n;
	}
	
	for(int i = 0;i < n;i++){
		cin >> mon[i].name >> mon[i].shu;
	}
	
	max = 0;
	for(int i = 1;i < n;i++){
		if(mon[max].shu < mon[i].shu){
			max = i;
		}
	}
	cout << mon[max].name << " " 
		<< mon[max].shu << " ";
	
	return 0;
}
