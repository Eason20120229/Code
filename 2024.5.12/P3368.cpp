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
    }
    while (m-- != 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        } else
        {
            int k;
            cin >> k;
            cout << a[k] + sum(k) << endl;
        }
    }
    return 0;
}
