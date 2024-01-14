/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-22 15:48
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int vis[100] = {0, 1};
bool book[100];
int n;

bool f(int n) {
	int t = (int)sqrt(n);
	for (int i = 2; i <= t; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void dfs(int m) {
	if (m == n + 1 && f(vis[m - 1] + vis[1])) {
		cout << vis[1];
		for (int i = 2; i <= n; i++) {
			cout << " " << vis[i];
		}
		cout << endl;
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (!book[i] && f(vis[m - 1] + i)) {
			book[i] = true;
			vis[m] = i;
			dfs(m + 1);
			book[i] = false;
		}
	}
}

int main() {
	cin >> n;
	if (n % 2 == 0) {
		dfs(2);
	}
	return 0;
}

