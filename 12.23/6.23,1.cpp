#include<iostream>
#include<fstream>

using namespace std;

char a[102][102] = {};

int main(){
	int n,m,h = 0;
	cin >> n >> m;
	
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	cout << endl;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(a[i][j] == '*'){
				cout << '*';
			}else{
				if(a[i - 1][j - 1] == '*')h++;
				if(a[i][j - 1] == '*')h++;
				if(a[i + 1][j - 1] == '*')h++;
				if(a[i - 1][j] == '*')h++;
				if(a[i + 1][j] == '*')h++;
				if(a[i - 1][j + 1] == '*')h++;
				if(a[i][j + 1] == '*')h++;
				if(a[i + 1][j + 1] == '*')h++;
				cout << h;
			}
			h = 0;
		}
		cout << endl;
	}
	return 0;
} 
