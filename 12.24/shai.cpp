#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int a[100000001],cnt = 0;
int f[100000001];

int main(){
	freopen("1.txt","w",stdout);
	int n;
	cin >> n;
	for(int i = 2;i <= n;i++){
		if(!f[i]){
			a[cnt++] = i;
			cout << i << " ";
		}
		for(int j = 0;j < cnt && i * a[j] <= n;j++){
			f[i * a[j]] = 1;
			if(i % a[j] == 0) break;
		}
	}
	cout << endl << cnt;
	return 0;
}


