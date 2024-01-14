#include <iostream>
#include <string>

using namespace std;

int main(){
	string name;
	bool first = true;
	cin >> name;
	int l = name.length();
	for(int i = 0;i < l;i++){
		if(name[i] >= 'A' && name[i] <= 'Z')
			name[i] += 32;
		if(name[i] >= 'a' && name[i] <= 'z' && first){
			name[i] -= 32;
			first = false;
		}
	}
	cout << name;
	return 0;
}
