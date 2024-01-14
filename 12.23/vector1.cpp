#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <list> 
using namespace std;

typedef *a A;

class a{
public:
	 itr(){
		return 2345; 
	}
};

int main(){
	a A;
	vector<int> :: iterator v;
	int a[5] = {12,3,4,5,6};
	vector<int> n(a,a + 5);
	for(v = n.begin();v != n.end();v++){
		cout << *v << " ";
	}
	cout << endl;
	cout << (a::itr);
	return 0;
}


