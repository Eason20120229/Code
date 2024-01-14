#include <iostream>
#include <string>

using namespace std;

struct a{
	string name;
	double d;
	int m;
	char c;
};

a h[1000];

int main(){
	int n,p,mon = 0,max = 0,maxi;
	cin >> n;
	for(int i = 0;i < n;i++){
		mon = 0;
		cin >> h[i].name >> h[i].d >> h[i].m >> h[i].c;
		if(h[i].d > 9){
			mon += 900; 
		}else if(h[i].d > 8){
			mon += 800;
		}else if(h[i].d > 7){
			mon += 700;
		}
		mon -= 50 * h[i].m;
		if(h[i].c == 'Y'){
			mon += 500;
		}
		if(mon > max){
			max = mon;
			maxi = i;
		}
	}
	cout << h[maxi].name;
	return 0;
}
