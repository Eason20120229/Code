/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-29 14:05
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

void qsort(int a[], int i, int j) {
	if (i >= j)
		return;
	int t = a[i];
	int l = i + 1, r = j;
	while (l <= r) {
		while (l <= r && a[l] <= t)
			l++;
		while (l <= r && a[r] > t)
			r--;
		if (l < r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	swap(a[i], a[r]);
	qsort(a, i, r - 1);
	qsort(a, r + 1, j);
}

int a[10000], n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	qsort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
