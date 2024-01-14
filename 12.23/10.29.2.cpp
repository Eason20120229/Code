/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-29 14:05
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[10000], N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < N; i++) {
		int t = i;
		for (int j = i - 1; j >= 0; j--) {
			if (a[t] < a[j]) {
				swap(a[t], a[j]);
				t = j;
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
