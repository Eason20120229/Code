/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-19 14:39
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[10000][10000];

int main() {
	int m, n, k;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cin >> k;
	while (k--) {
		int h;
		cin >> h;
		int i = 0, j = m - 1, f = 0;
		while (i < n && j >= 0) {
			while (j >= 0 && a[i][j] > h)
				j--;
			while (i < n && a[i][j] < h)
				i++;
			if (a[i][j] == h) {
				f = 1;
				break;
			}
		}
		if (f) {
			printf("(%d,%d)\n", i + 1, j + 1);
		} else {
			printf("(%d,%d)\n", 0, 0);
		}
	}
	return 0;
}
