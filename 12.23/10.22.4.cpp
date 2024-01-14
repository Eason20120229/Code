/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-22 15:48
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int vis[100];
bool book[100];
int r, n;

void dfs(int last, int m) {
	if (m == r) {
		cout << vis[0];
		for (int i = 1; i < r; i++) {
			cout << " " << vis[i];
		}
		cout << endl;
		return;
	}
	for (int i = last + 1; i <= n; i++) {
		if (!book[i - 1]) {
			book[i - 1] = true;
			vis[m] = i;
			dfs(i, m + 1);
			vis[m] = 0;
			book[i - 1] = false;
		}
	}
}

int main() {
	cin >> n >> r;
	dfs(0, 0);
	return 0;
}
