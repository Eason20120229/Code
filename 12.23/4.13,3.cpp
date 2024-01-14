#include<iostream>
#include<cstring>

using namespace std;

char a[101];

int lena;



int main(){
	
	//含有空格的输入
	cin.getline(a,101);

	int p0 = strlen(a) - 1;
	int p1 = p0;
	while(1){
		while(a[p0] != ' ' && p0) p0--;
		if(p0 == 0){
			for(int i = p0;i <=p1;i++){
				cout << a[i];
			}
			break;
		}else{
			for(int i = p0 + 1;i <=p1;i++){
				cout << a[i];
			}
			cout << ' ';
			p0--;
			p1 = p0;
		}
	}
	
	return 0;
}
