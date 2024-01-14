#include <iostream>
#include <algorithm>

using namespace std;

struct Student{
	char name[10];
	int chinese;
	int maths;
	int all;
};

bool comp(Student a,Student b){
	return a.all > b.all;
}

int main(){
	int n;
	Student stu[100];
	
	cin >> n;
	
	while(n > 100 && n < 1){
		cin >> n;
	}
	
	for(int i = 0;i < n;i++){
		cin >> stu[i].name >> stu[i].chinese >> stu[i].maths;
		stu[i].all = stu[i].chinese + stu[i].maths;
	}
	
	sort(stu,stu+n,comp);
	for(int i = 0;i < n;i++){
		cout << stu[i].name << " " 
			<< stu[i].chinese << " " 
			<< stu[i].maths << " " 
			<< stu[i].all << "\n" ;
	}
	
	
	return 0;
}
