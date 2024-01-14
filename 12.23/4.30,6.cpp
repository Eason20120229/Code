#include <iostream>
#include <algorithm>

using namespace std;


bool comp(int a,int b){
	return a > b;
}

int main(){
	int n;
	int stu[10000];
	
	cin >> n;
	while(n < 5){
		cin >> n;
	}
	for(int i = 0;i < n;i++){
		cin >> stu[i];
	}
	
	sort(stu,stu + n,comp);
	for(int i = 0;i < 5;i++){
		cout << stu[i] << "	";
	}
	
	
	return 0;
}
