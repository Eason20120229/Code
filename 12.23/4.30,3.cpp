#include <iostream>

using namespace std;

struct Student{
	int name;
	int tall;
};

int main(){
	int n,max;
	Student stu[100];
	
	cin >> n;
	
	while(n > 100 && n < 1){
		cin >> n;
	}
	
	for(int i = 0;i < n;i++){
		cin >> stu[i].tall;
		while(stu[i].tall > 200 && stu[i].tall < 1){
			cin >> stu[i].tall;
		}
		stu[i].name = i + 1;
	}
	
	max = 0;
	for(int i = 1;i < n;i++){
		if(stu[max].tall < stu[i].tall){
			max = i;
		}
	}
	cout << stu[max].name << " " 
		<< stu[max].tall << " ";
	
	return 0;
}
