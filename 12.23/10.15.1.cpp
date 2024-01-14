#include <bits/stdc++.h>

using namespace std;

struct g{
	double m;
	string n;
};

g a[10000];

bool cmp(g a,g b){
	return a.m < b.m;
}

int main(){
	int c,ans = 0,i = 0;
	double b;
	cin >> b >> c;
	for(int i = 0;i < c;i++){
		cin >> a[i].n >> a[i].m;
	}
	sort(a,a + c,cmp);
	while(b > a[i].m){
		b -= a[i].m;
		ans++;
		i++;
	}
	cout << a[0].n;
	for(int i = 1;i < ans;i++){
		cout << " " << a[i].n;
	}
}
