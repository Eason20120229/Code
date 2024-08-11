#include <iostream>
#define LL long long
#define N  100001

using namespace std;

LL arr[N];

struct
{
    LL tag;
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

void addtag(LL u, LL l, LL r, LL k)
{
    tree[u].val += k * (r - l + 1);
    tree[u].tag += k;
}

void push_up(LL u)
{
    tree[u].val = tree[ls(u)].val + tree[rs(u)].val;
}

void push_down(LL u, LL l, LL r)
{
    if (tree[u].tag != 0)
    {
        LL m = (l + r) >> 1;
        addtag(ls(u), l, m, tree[u].tag);
        addtag(rs(u), m + 1, r, tree[u].tag);
        tree[u].tag = 0;
    }
}

void build(LL u, LL l, LL r)
{
    tree[u].tag = 0;
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

void update(LL u, LL l, LL r, LL x, LL k)
{
    if (l == r)
    {
        tree[u].val += k;
        return;
    }
    push_down(u, l, r);
    LL m = (l + r) >> 1;
    if (x <= m)
    {
        update(ls(u), l, m, x, k);
    }
    if (x > m)
    {
        update(rs(u), m + 1, r, x, k);
    }
    push_up(u);
}

void updateline(LL u, LL l, LL r, LL sl, LL sr, LL k)
{
    if (sl <= l && r <= sr)
    {
        addtag(u, l, r, k);
        return;
    }
    push_down(u, l, r);
    LL m = (l + r) >> 1;
    if (sl <= m)
    {
        updateline(ls(u), l, m, sl, sr, k);
    }
    if (sr > m)
    {
        updateline(rs(u), m + 1, r, sl, sr, k);
    }
    push_up(u);
}

auto findone(LL u, LL l, LL r, LL i) -> LL
{
    if (l == r)
    {
        return tree[u].val;
    }
    push_down(u, l, r);
    LL m = (l + r) << 1;
    if (i <= m)
    {
        return findone(ls(u), l, m, i);
    }
    return findone(rs(u), m + 1, r, i);
}

auto sum(LL u, LL l, LL r, LL sl, LL sr) -> LL
{
    // cout << u << " " << l << " " << r << endl;
    if (sl <= l && r <= sr)
    {
        return tree[u].val;
    }
    push_down(u, l, r);
    LL ans = 0;
    LL m = (l + r) >> 1;
    // cout << m << endl;
    if (sl <= m)
    {
        ans += sum(ls(u), l, m, sl, sr);
    }
    if (m < sr)
    {
        ans += sum(rs(u), m + 1, r, sl, sr);
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
        char s;
        cin >> s;
        if (s == 'C')
        {
            LL x, y, k;
            cin >> x >> y >> k;
            updateline(1, 1, n, x, y, k);
        } else
        {
            LL x, y;
            cin >> x >> y;
            cout << sum(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
