#include <iostream>
#include <string>

using namespace std;

void h(int n,string a,string b,string c){
	static int n2 = 0;
	if(n == 0){
		return;
	}
	h(n - 1,a,c,b);
	n2++;
	cout << n2 << ":" << a << "--->" << c << endl;
	
	h(n - 1,b,a,c);
	
}

int main(){
	h(4,"a","b","c");
	return 0;
}
