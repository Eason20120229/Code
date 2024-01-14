#include <bits/stdc++.h>
using namespace std;
struct Cc{
	int t;
	int m;
	double h;
};
void mysort(Cc s[],int l){
	for(int i = 1;i <= l;i++){
		for(int j = i;j <= l;j++){
			if(s[i].h < s[j].h){
				swap(s[i],s[j]);
			}
		}
	}
}
int T,M,C = 0;
Cc c[1000];
int main(){
	cin >> T >> M;
	for(int i = 1;i <= M;i++){
		cin >> c[i].t >> c[i].m;
		c[i].h = (double)c[i].m / c[i].t * 1.0;
	}
	mysort(c,M);
	int h = 1;
	while(h <= M){
		if(T >= c[h].t){
			T -= c[h].t;
			C += c[h].m;
		}else{
			h++;
		}
	}
	cout << C;
	return 0;
}
