#include <iostream>
#define LL long long
#define N  200001

using namespace std;

LL arr[N];

struct
{
    LL val;
} tree[4 * N];

LL ls(LL u)
{
    return u << 1;
}

LL rs(LL u)
{
    return u << 1 | 1;
}

void push_up(LL u)
{
    tree[u].val = min(tree[ls(u)].val, tree[rs(u)].val);
}

void build(LL u, LL l, LL r)
{
    if (l == r)
    {
        tree[u].val = arr[l];
        return;
    }
    LL m = (l + r) >> 1;
    build(ls(u), l, m);
    build(rs(u), m + 1, r);
    push_up(u);
}

auto sum(LL u, LL l, LL r, LL sl, LL sr) -> LL
{
    // cout << u << " " << l << " " << r << endl;
    if (sl <= l && r <= sr)
    {
        return tree[u].val;
    }
    LL ans = 0x7ffffff;
    LL m = (l + r) >> 1;
    // cout << m << endl;
    if (sl <= m)
    {
        ans = min(ans, sum(ls(u), l, m, sl, sr));
    }
    if (m < sr)
    {
        ans = min(ans, sum(rs(u), m + 1, r, sl, sr));
    }
    return ans;
}

auto main() -> int
{
    LL n;
    LL m;
    cin >> n >> m;
    for (LL i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int x;
        int y;
        cin >> x >> y;
        cout << sum(1, 1, n, x, y) << " ";
    }
    return 0;
}
