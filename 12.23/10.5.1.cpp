#include <bits/stdc++.h> 

using namespace std;

template<typename tn>
class Q{
	int fro = 0;
	int rear = 0;
	tn q[100] = {};
public:
	int size(){
		return (100 + this -> rear - this -> fro) % 100;
	}
	
	void push(tn n){
		if(this -> size() <= 100){
			this -> q[this -> rear] = n;
			this -> rear = (this -> rear + 101) % 100;
		}
	}
	
	void pop(){
		if(!this -> empty()){
			this -> fro = (this -> fro + 101) % 100;
		}
	}
	
	bool empty(){
		if(this -> size() > 0) return false;
		return true;
	}
	
	tn front(){
		return q[this -> fro];
	}
	
	tn back(){
		return q[this -> rear - 1];
	}
	
};

int main(){
	Q<int> q;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		q.push(i);
	}
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
		if(q.size() >= 2){
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}
