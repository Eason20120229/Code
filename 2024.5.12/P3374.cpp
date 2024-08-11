#include <iostream>
#define N 500001

using namespace std;

int n, m;
int a[N], s[N];

int lowbit(int x)
{
    return x & (-x);
}

void add(int idx, int i)
{
    int u = idx;
    while (u <= n)
    {
        s[u] += i;
        u += lowbit(u);
    }
}

int sum(int idx)
{
    int u = idx;
    int ret = 0;
    while (u > 0)
    {
        ret += s[u];
        u -= lowbit(u);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i]);
    }
    while (m-- != 0)
    {
        int t, x, k;
        cin >> t >> x >> k;
        if (t == 1)
        {
            add(x, k);
        } else
        {
            cout << (sum(k) - sum(x - 1)) << endl;
        }
    }
    return 0;
}
