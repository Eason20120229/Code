/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-19 14:39
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int f(int a[], int k, int n) {
	int s = 0;
	int e = n - 1;
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (a[mid] == k) {
			break;
		}
		if (a[mid] < k) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}
	return s;
}

int a[1000000];

int main() {
	int m, n, k;
	cin >> m >> n;
	for (int i = 0; i < m * n; i++) {
		cin >> a[i];
	}
	cin >> k;
	while (k--) {
		int h;
		cin >> h;
		int t = f(a, h, n * m);
		int t1 = t % n;
		int t2 = t / n;
		if (a[t] == h) {
			printf("(%d,%d)", t1 + 1, t2 + 1);
		} else {
			printf("(%d,%d)", 0, 0);
		}
	}
	return 0;
}
