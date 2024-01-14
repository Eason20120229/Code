#include<iostream>
#include<string>

using namespace std;

string check(int n,int d){
	
	for(int i;;i++){
		
		if(n % 10 == d){
			return "true";
		}
		n /= 10;
		if(n == 0){
			return "false";
		}
		
	}
}


int main(){
	int n,d;
	
	cin >> n >> d;
	cout << check(n,d) << endl;
	return 0;
}
