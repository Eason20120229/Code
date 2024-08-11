/* AC自动机 */
#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
int n;
char str[1000010];
int ch[N][26], cnt[N], idx;
int ne[N];

void insert(char *s)
{  // 建树
    int len = strlen(s);
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int c = s[i] - 'a';
        if (!ch[p][c])
        {
            ch[p][c] = ++idx;
        }
        p = ch[p][c];
    }
    cnt[p]++;
}
void build()
{  // 建AC自动机
    queue< int > q;
    for (int i = 0; i < 26; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int v = ch[u][i];
            if (v)
            {
                ne[v] = ch[ne[u]][i];
                q.push(v);
            } else
            {
                ch[u][i] = ch[ne[u]][i];
            }
        }
    }
}
int query(char *s)
{
    int ans = 0;
    for (int k = 0, i = 0; s[k] != 0; k++)
    {
        i = ch[i][s[k] - 'a'];
        for (int j = i; j != 0 && cnt[j] != -1; j = ne[j])
        {
            ans += cnt[j], cnt[j] = -1;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str, insert(str);
    }
    build();
    cin >> str;
    cout << query(str) << endl;
    return 0;
}
