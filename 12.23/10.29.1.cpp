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
	for (int i = 0; i < N - 1; i++) {
		int min = 100, id = -1;
		for (int j = i + 1; j < N; j++) {
			if (a[j] < min) {
				min = a[j];
				id = j;
			}
		}
		swap(a[i], a[id]);
		cout << a[i] << " ";
	}
	cout << a[N - 1];
	return 0;
}
