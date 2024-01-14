#include <iostream>
#include <string>

using namespace std;

int main(){
	string a[100],C;
	int i = 0;
	while(cin >> C)
		a[i++] = C;
	for(int j = 0;j < i;j++){
		if(a[j] != a[i - 1 - j]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
