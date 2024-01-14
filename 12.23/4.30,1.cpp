#include <iostream>

using namespace std;

struct Student{
	char name[10];
	int chinese;
	int maths;
	int all;
};

int main(){
	int n,max;
	Student stu[100];
	
	cin >> n;
	
	while(n > 100 && n < 1){
		cin >> n;
	}
	
	for(int i = 0;i < n;i++){
		cin >> stu[i].name >> stu[i].chinese >> stu[i].maths;
		stu[i].all = stu[i].chinese + stu[i].maths;
	}
	
	max = 0;
	for(int i = 1;i < n;i++){
		if(stu[max].all < stu[i].all){
			max = i;
		}
	}
	cout << stu[max].name << " " 
		<< stu[max].chinese << " " 
		<< stu[max].maths << " " 
		<< stu[max].all << " " ;
	
	return 0;
}
