/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-03 14:01
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[10000][10000];

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int t, h;
		cin >> t >> h;
		t--;
		v--;
		a[t][h] = 1;
		a[h][t] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
