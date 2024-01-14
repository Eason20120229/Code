#include <bits/stdc++.h> 

using namespace std;

template<typename tn>
class Q{
public:
	int fro = 0;
	int rear = 0;
	tn q[100] = {};
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
	Q<char> q;
	cin >> q.q;
	q.rear = strlen(q.q);
	while(!q.empty()){
		cout << q.front();
		q.pop();
		if(!q.empty()){
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}
