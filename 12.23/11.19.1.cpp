#include <bits/stdc++.h>

using namespace std;

#define d double

d f(d a, int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return a;
	d h = f(a, n / 2);
	if (n % 2) {
		return h * h * a;
	} else {
		return h * h;
	}
}

int main() {
	//freopen("P1226_6.in","r",stdin);
	//freopen("P1226_6.out","w",stdout);
	long long c, t;
	double a, b, ans = 1, t2;
	cin >> a >> b >> c;
//	t = c;
//	t2 = b + 1;
//	while (t) {
//		if (t & 1) {
//			ans *= t2;
//		}
//		t2 *= t2;
//		t /= 2;
//	}
	printf("%.3lf", (f(b + 1, c) * a));
	return 0;
}
