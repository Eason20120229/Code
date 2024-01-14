#include <bits/stdc++.h>

using namespace std;

int n,ans = 0,av;
int a[10000];

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		av += a[i];
	}
	av = av / n;
	for(int i = 0;i < n;i++){
		if(a[i] != av){
			int t = 5 - a[i];
			a[i] += t;
			a[i + 1] -= t;
			ans++;
		}
	}
	cout << ans;
	return 0;
}


