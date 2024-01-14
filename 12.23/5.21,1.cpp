#include <iostream>

using namespace std;

struct student{
	string name;
	int number;
	double chinese;
	double maths;
	double english;
};
int main(){
	student stu;
	cin >> stu.name
		>> stu.number
		>> stu.chinese
		>> stu.maths
		>> stu.english;
		
	cout << stu.name
		<<endl
		<< stu.number
		<<endl
		<< stu.chinese
		<<endl
		<< stu.maths 
		<<endl
		<< stu.english
		<<endl;
	
	return 0;
}
