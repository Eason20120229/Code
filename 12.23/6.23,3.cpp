#include<iostream>
#include<fstream>

using namespace std;

int a[1000][1000] = {};

int main(){
	int n,m;
	
	cin >> m >> n;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cin >> a[i][j];
		}
	}
	cout << a[0][0] << " ";
	for(int i = 1;i < n;i++){
		int x = 0;
		int y = i;
		while(x < m && y >= 0){
			cout << a[x][y] << " ";
			x++;
			y--;
		}
	}
	for(int i = 1;i < m;i++){
		int x = i;
		int y = n - 1;
		while(x < m && y >= 0){
			cout << a[x][y] << " ";
			x++;
			y--;
		}
	}
	return 0;
} 
