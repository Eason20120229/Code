/* phone list*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int Z = 10;
int ch[N][Z];
bool bo[N];
int tot, T, n;
char s[21];
bool insert(char *s)
{
    size_t len = strlen(s);
    int u = 0;
    bool flag = 0;
    for (int i = 0; i < len; i++)
    {
        int c = s[i] - '0';
        // 如果是空节点，就插入
        if (!ch[u][c])
            ch[u][c] = ++tot;
        else if (i == len - 1)
        {
            flag = 1;  // 没有插入任何新节点
            return flag;
        }
        u = ch[u][c];
        if (bo[u])
        {
            flag = true;  // 经过某个有标记的节点
            return flag;
        }
    }
    bo[u] = true;
    return flag;
}
// 初始化数组
void clear()
{
    memset(ch, 0, sizeof(ch));
    memset(bo, 0, sizeof(bo));
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        clear();
        tot = 0;
        bool ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            if (insert(s))
                ans = 1;
        }
        if (!ans)
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");
    }
    return 0;
}
