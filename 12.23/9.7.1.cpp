#include <iostream>

using namespace std;

int T,M;
int t[1000],m[1000],f[2000][2000];

int main(){
	cin >> T >> M;
	for(int i = 1;i <= M;i++){
		cin >> t[i] >> m[i];
	}
	for(int i = 1;i <= M;i++){
		for(int j = 1;j <= T;j++){
			if(j >= t[i]){
				f[i][j] = max(f[i][j - t[i]] + m[i],f[i][j - 1]);
			}else{
				f[i][j] = f[i][j - 1];
			}
		}
	}
	cout << f[M][T];
	return 0;
}
