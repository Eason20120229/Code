#include <iostream>
#include <cstring>

using namespace std;

char a1[30][40] = {""};

int main(){
	string a;
	int first = 1,j = -1,h = 0,k = 0;
	memset(a1[1],0,sizeof(a1));
	getline(cin,a);
	for(int i = 0;i < a.length();i++,h++){
		if(a[i] != ' '){
			if(first){
				first = 0;
				j++;
				h = 0;
			}
			a1[j][h] = a[i]; 
		}else if(!first && a[i] == ' ') first = 1;		
	}
	for(k = 39;k >= 0 && a1[k][0] == '\0';k--);
	k++;
	for(int i = 0;i < (k / 2 + k % 2);i++){
		if(strcmp(a1[i],a1[k - i - 1])){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
