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
	Q<string> q;
	char ch;
	while(cin >> ch){
		if(ch == 'B'){
			string s;
			cin >> s;
			q.push(s);
		}else{
			if(!q.empty()){
				cout << "-" << q.front() << endl;
				q.pop();
			}else{
				cout << "-None" << endl;
			}
		}
	}
	return 0;
}
