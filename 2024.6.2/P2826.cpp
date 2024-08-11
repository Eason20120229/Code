#include <iostream>
#define LL long long
#define N  200001

using namespace std;

int arr[N];

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

void addtag(LL u, LL l, LL r)
{
    tree[u].val = (r - l + 1) - tree[u].val;
    tree[u].tag += 1;
    tree[u].tag %= 2;
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
        addtag(ls(u), l, m);
        addtag(rs(u), m + 1, r);
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
    // cout << "-------------------" << endl;
    // cout << tree[u].val << endl;
    // cout << u << " " << l << " " << r << endl;
}

void updateline(LL u, LL l, LL r, LL sl, LL sr)
{
    if (sl <= l && r <= sr)
    {
        addtag(u, l, r);
        return;
    }
    push_down(u, l, r);
    LL m = (l + r) >> 1;
    if (sl <= m)
    {
        updateline(ls(u), l, m, sl, sr);
    }
    if (sr > m)
    {
        updateline(rs(u), m + 1, r, sl, sr);
    }
    push_up(u);
}

auto sum(LL u, LL l, LL r, LL sl, LL sr) -> LL
{
    // cout << tree[u].val << endl;
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
    build(1, 1, n);
    while (m--)
    {
        int s;
        cin >> s;
        if (s == 0)
        {
            LL x, y;
            cin >> x >> y;
            updateline(1, 1, n, x, y);
        } else
        {
            LL x, y;
            cin >> x >> y;
            cout << sum(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
