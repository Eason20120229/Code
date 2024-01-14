/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-04 08:25
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int *a, n;

void part() {
	int t = a[0];
	int i = 1;
	int j = n - 1;
	while (i <= j) {
		while (a[i] <= t && i <= j)
			i++;
		while (a[j] > t && i <= j)
			j--;
		if (i < j) {
			swap(a[i++], a[j--]);
		}
	}
	swap(a[0], a[j]);
}

int main() {
	cin >> n;
	a = new int(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	part();
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
