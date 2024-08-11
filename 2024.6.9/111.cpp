#include <iostream>
using namespace std;

long long k[100001];
long long g[100001], h[100001];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &g[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i][1] = g[i] * h[1];
        for (int j = 2; j <= m; j++)
        {
            a[i][j] = g[i] * h[j];
            k[i] = max(k[i], a[i][j]);
        }
    }
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int mk = k[l1], id = l1;
        for (int i = l1 + 1; i <= r1; i++)
        {
            if (mk < k[i])
            {
                mk = k[i];
                id = i;
            }
        }
        int ma = a[id][l2];
        int ida = l2;
        for (int i = l2 + 1; i <= r2; i++)
        {
            if (ma < a[id][i])
            {
                ma = a[id][i];
                ida = i;
            }
        }
        cout << id << " " << ida << endl;
    }
    return 0;
}
