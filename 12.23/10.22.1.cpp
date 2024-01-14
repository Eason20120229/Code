/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-22 14:10
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool e[10001], a[20200], b[20200];
int vis[10001][10001], id = 1;
int m;

bool OK(int x, int y) {
	if (e[y] || a[x - y + m] || b[x + y - m]) {
		return false;
	}
	return true;
}


void dfs(int n) {
	if (n == m + 1) {
		cout << "No." << id << endl;
		for (int i = 1; i <= m; i++) {
			cout << vis[i][1];
			for (int j = 2; j <= m; j++) {
				cout << " " << vis[i][j];
			}
			cout << endl;
		}
		cout << endl;
		id++;
	}
	for (int i = 1; i <= m; i++) {
		if (OK(n, i)) {
			e[i] = a[n - i + m] = b[n + i - m] = true;
			vis[n][i] = 1;
			dfs(n + 1);
			vis[n][i] = 0;
			e[i] = a[n - i + m] = b[n + i - m] = false;
		}
	}
}

int main() {
	cin >> m;

	dfs(1);

	return 0;
}
