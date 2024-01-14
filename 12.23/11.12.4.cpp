/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-12 15:26
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[1000], n, k;
	string c, k1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c[0] <= '9' && c[0] >= '2') {
			a[i] = c[0] - '0';
		} else if (c == "10") {
			a[i] = 10;
		} else if (c[0] == 'A') {
			a[i] = 1;
		} else if (c[0] == 'J') {
			a[i] = 11;
		} else if (c[0] == 'Q') {
			a[i] = 12;
		} else if (c[0] == 'K') {
			a[i] = 13;
		}
	}

	cin >> k1;
	if (k1[0] <= '9' && k1[0] >= '2') {
		k = k1[0] - '0';
	} else if (k1 == "10") {
		k = 10;
	} else if (k1[0] == 'A') {
		k = 1;
	} else if (k1[0] == 'J') {
		k = 11;
	} else if (k1[0] == 'Q') {
		k = 12;
	} else if (k1[0] == 'K') {
		k = 13;
	}
	int s = 0;
	int e = n - 1;
	int mid;
	while (s <= e) {
		mid = (s + e) / 2;

		if (a[mid] == k) {
			break;
		}
		if (a[mid] < k) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	for (int i = 0; i < mid; i++) {
		cout << a[i];
	}
	cout << k;
	for (int i = mid; i < n; i++) {
		cout << a[i];
	}
	return 0;
}
