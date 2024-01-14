/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-12 15:41
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct p {
	string v;
	int n;
} a[32], k;

int h(string k1) {
	string m[13] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};
	for (int i = 0; i < 13; i++) {
		if (k1 == m[i]) {
			return i;
		}
	}
	return -1;
}

int f(p a[], int k, int n) {
	int s = 0;
	int e = n - 1;
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (a[mid].n == k) {
			break;
		}
		if (a[mid].n < k) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].v;
		string v = a[i].v;
		a[i].n = h(v);
	}
	cin >> k.v;
	k.n = h(k.v);
	int t = f(a, k.n, n);
	for (int i = 0; i < t; i++) {
		cout << a[i].v << " ";
	}
	cout << k.v << " ";
	for (int i = t; i < n; i++) {
		cout << a[i].v << " ";
	}
	return 0;
}
