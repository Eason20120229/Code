#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main(){
	for(int i = 1;i <= 10;i++){
		q.push(i);
	}
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;
	int sum = 0;
	for(int i = 0;i < 10;i++){
		sum += q.front();
		cout << q.front() << " ";
		q.pop();
	} 
	cout << endl << sum;
	return 0;
} 
