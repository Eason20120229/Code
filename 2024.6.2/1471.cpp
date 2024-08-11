#include <iostream>
#define N 100001

using namespace std;

double arr[N];

struct
{
    int tag;
    int val;
} tree[4 * N];

int ls(int u)
{
    return u << 1;
}

int rs(int u)
{
    return u << 1 | 1;
}

void addtag(int u, int l, int r, int k)
{
    tree[u].val += k * (r - l + 1);
    tree[u].tag += k;
}

void push_up(int u)
{
    tree[u].val = tree[ls(u)].val + tree[rs(u)].val;
}

void push_down(int u, int l, int r)
{
    if (tree[u].tag != 0)
    {
        int m = (l + r) >> 1;
        addtag(ls(u), l, m, tree[u].tag);
        addtag(rs(u), m + 1, r, tree[u].tag);
        tree[u].tag = 0;
    }
}

void build(int u, int l, int r)
{
    tree[u].tag = 0;
    if (l == r)
    {
        tree[u].val = arr[l];
        return;
    }
    int m = (l + r) >> 1;
    build(ls(u), l, m);
    build(rs(u), m + 1, r);
    push_up(u);
}

void updateline(int u, int l, int r, int sl, int sr, double k)
{
    if (sl <= l && r <= sr)
    {
        addtag(u, l, r, k);
        return;
    }
    push_down(u, l, r);
    int m = (l + r) >> 1;
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

auto sum(int u, int l, int r, int sl, int sr) -> double
{
    // cout << u << " " << l << " " << r << endl;
    if (sl <= l && r <= sr)
    {
        return tree[u].val;
    }
    push_down(u, l, r);
    int ans = 0;
    int m = (l + r) >> 1;
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

auto sum_xy(int u, int l, int r, int sl, int sr) -> double
{
    // cout << u << " " << l << " " << r << endl;
    if (sl <= l && r <= sr)
    {
        return tree[u].val;
    }
    push_down(u, l, r);
    int ans = 0;
    int m = (l + r) >> 1;
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
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            int x, y;
            double k;
            cin >> x >> y >> k;
            updateline(1, 1, n, x, y, k);
        } else if (s == 1)
        {
            int x, y;
            cin >> x >> y;
            cout << sum(1, 1, n, x, y) << endl;
        } else
        {
            int x, y;
            cin >> x >> y;
            cout << sum_xy(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
