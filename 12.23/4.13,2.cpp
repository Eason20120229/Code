#include<iostream>
#include<cstring>

using namespace std;

char a[101];



string b[101];

int split(char h[],string b[]){
	int i = 0,len = 0;
	while(1){
		while(h[i] != ' '){
			b[len] += a[i];
			i++;
			if(h[i] == '\0') return len;
		}
		len++;
		i++;
	}
}



int main(){
	
	
	//含有空格的输入
	cin.getline(a,101);
	int len = split(a,b);
	for(int j = len;j >= 0;j--){
		cout << b[j] << " ";
	}
	return 0;
}
