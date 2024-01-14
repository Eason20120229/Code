#include <bits/stdc++.h>

using namespace std;

int top = 0;
char s[100];

char gettop(){
	return s[top - 1];
} 

void clear(){
	top = 0;
}

void push(char x){
	if(top < 100){
		s[top] = x;
		top += 1;
	}
}

char pop(){
	if(top > 0){
		top -= 1;	
		return s[top];
	}
	return '|';
}

bool empty(){
	if(top > 0) return false;
	else return true;
}

int main(){
	string a;
	cin >> a;
	for(int i = 0;i < a.length();i++){
		if(gettop() == '(' && a[i] == ')' || gettop() == '[' && a[i] == ']'){
			pop();
		}else if(a[i] == '('|| a[i] == '[' && gettop() != '('){
			push(a[i]);
		}else{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}


