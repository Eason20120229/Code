/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-22 14:10
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int vis[10001][10001];
int m, n, ans;

void dfs(int x, int y, int step) {
	if (!vis[x][y] && x >= 0 && y >= 0 && x <= m && y <= n) {
		vis[x][y] = step;
		if (x == m && y == n) {
			ans++;
			for (int i = 0; i <= m; i++) {
				cout << vis[i][0];
				for (int j = 1; j <= n; j++) {
					cout << " " << vis[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}

		dfs(x + 1, y - 2, step + 1);
		dfs(x + 2, y - 1, step + 1);
		dfs(x + 2, y + 1, step + 1);
		dfs(x + 1, y + 2, step + 1);
		vis[x][y] = 0;
	}
}

int main() {
	cin >> m >> n;

	dfs(0, 0, 1);
	cout << ans;
	return 0;
}
