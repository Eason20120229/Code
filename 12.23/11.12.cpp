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
	int k;
	cin >> k;
	int s = 1;
	int e = 100;
	int cnt = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		cnt++;

		if (mid == k)
			break;
		if (mid < k) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	cout << cnt;
	return 0;
}
