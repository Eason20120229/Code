/*********************************************************************
    ������:
    ��Ȩ:
    ����:
    ����: 2023-11-12 14:23
    ˵��:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
	double k, s, e, mid, exp = 0.001, cnt = 0;
	cin >> k;
	s = 1;
	e = k;
	while (s < e) {
		mid = (s + e) / 2;
		if (fabs(k - mid * mid) < exp) {
			printf("%.3lf", mid);
			break;
		} else if (mid * mid < k) {
			s = mid;
		} else {
			e = mid;
		}
	}
	return 0;
}
