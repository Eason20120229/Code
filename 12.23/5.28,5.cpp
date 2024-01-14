#include <iostream>
#include <string>


using namespace std;

void search(int s,int n){
	static int a[10],book[10];
	if(s == n + 1){
		for(int i = 1;i <= n;i++){
			cout << a[i];
		}
		cout << endl;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(book[i] == 0){
			a[s] = i;
			book[i] = 1;
			search(s + 1,n);
			book[i] = 0;
		}
	}
}

int main(){
	int n;
	cin >> n;
	while(n > 9 || n < 0){
		cin >> n;
	}
	search(1,n);
	return 0;
}
