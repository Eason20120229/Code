/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-19 16:05
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[10000];

bool j(int x, int c) {
	int ans = 1, last = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[last] >= x) {
			ans++;
			last = i;
		}
	}
	return ans >= c;
}

int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int L = 0, R = n - 1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (j(mid)) {
			L++;
		} else {
			R--;
		}
	}
	cout << R;
	return 0;
}
