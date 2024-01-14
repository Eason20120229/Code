/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-19 16:33
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[10000];
int n, m;

bool check(int x) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i] - x >= 0 ? a[i] - x : 0;
		if (sum >= m) {
			return true;
		}
	}
	return false;
}

int main() {
	int l = 0, r = 0;
	int ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r = max(r, a[i]);
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
