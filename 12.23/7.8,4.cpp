#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string name[1000];
	cin >> n;
	cin >> name[0];
	string min = name[0];
	for(int i = 1;i < n;i++){
		cin >> name[i];
		if(name[i] < min) min = name[i];
	}
	cout << min;
	return 0;
}
