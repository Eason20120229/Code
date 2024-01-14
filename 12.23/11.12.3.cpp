/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-12 14:13
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, a[10000], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	int s = 0;
	int e = n - 1;
	int mid;
	int f;
	while (s <= e) {
		mid = (s + e) / 2;

		if (a[mid] == k) {
			f = 1;
			break;
		}
		if (a[mid] < k) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	if (f)
		cout << mid + 1;
	else
		cout << -1;
	return 0;
}
