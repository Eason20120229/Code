#include <bits/stdc++.h>


using namespace std;

void qu(int q,int s[8][8]){
	int s1[8][8];
	memcpy(s1,s,sizeof(s1));
	if(q == 0){
		for(int i = 0;i < 8;i++){
			for(int j = 0;j < 8;j++){
				if(s1[i][j] < 2){
					cout << 0 << " ";
				}else{
					cout << 1 << " ";
				}
			}
			cout << endl;
		}
	}else{
		for(int i = 0;i < 8;i++){
			if(s1[q - 1][i] == 0){
				int t = q - 1 - i;
				for(int j = 0;j < 8;j++){
					s1[q - 1][j] = 1;
					s1[j][q - 1] = 1;
					s1[t + j][j] = 1;
				}
				s1[q - 1][i] = 2;
				qu(q - 1,s1);
				memcpy(s1,s,sizeof(s1));
			}
		}
	}
	
}

int main(){
	int s[8][8];
	qu(8,s);
	return 0;
}



