#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	
	for(int i = 0,j = a.length() - 1;i < (a.length() / 2 + 1) && j >= (a.length() / 2 + 1);i++,j--){
		if(a[i] != a[j]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}


