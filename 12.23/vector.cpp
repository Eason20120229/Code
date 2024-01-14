#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
	for(int i = 0;i < 10;i++){
		int n;
		cin >> n;
		v.push_back(n);
	}
	for(int i = 0;i < 10;i++){
		cout << v[i] << " ";
	}
	cout << endl;
	for(int i = 0;i < 5;i++){
		cout << v[i] << " ";
	}
	return 0;
}


