#include <cstring>
#include <iostream>
#include <queue>
#include <string>

#define NUM 4
#define N   10000001
#define ULL unsigned long long
#define LEN 101

int idx = 0;
int chr[N][NUM];
int fail[N];
int cnt[N];
char strs[N][LEN];

int get_n(char chr)
{
    if (chr == 'E')
    {
        return 0;
    }
    if (chr == 'S')
    {
        return 1;
    }
    if (chr == 'W')
    {
        return 2;
    }
    return 3;
}

void insert(char *patt)
{
    int cur = 0;
    ULL len = strlen(patt);
    for (int i = 0; i < len; i++)
    {
        if (chr[cur][get_n(patt[i])] == 0)
        {
            chr[cur][get_n(patt[i])] = ++idx;
            // std::cout << cur << " " << patt[i] << " "<<
            // chr[cur][get_n(patt[i])] << std::endl;
        }
        cur = chr[cur][get_n(patt[i])];
    }
    // cnt[cur]++;
}

void build()
{
    std::queue< int > qbfs;
    for (int i = 0; i < NUM; i++)
    {
        if (chr[0][i] != 0)
        {
            qbfs.push(chr[0][i]);
        }
    }
    while (qbfs.size() != 0)
    {
        int cur = qbfs.front();
        qbfs.pop();
        for (int i = 0; i < NUM; i++)
        {
            int son = chr[cur][i];
            if (son != 0)
            {
                fail[son] = chr[fail[cur]][i];
                qbfs.push(son);
            } else
            {
                chr[cur][i] = chr[fail[cur]][i];
            }
        }
    }
}

void find(std::string str)
{
    int cur = 0;
    for (int k = 0; k < str.size(); k++)
    {
        cur = chr[cur][get_n(str[k])];
        for (int j = cur; j != 0 && cnt[j] != -1; j = fail[j])
        {
            cnt[j] = -1;
            // std::cout<<j<<" ";
        }
    }
}

int Find(char *str)
{
    int cur = 0;
    int ans = 0;
    ULL len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        cur = chr[cur][get_n(str[i])];
        if (cnt[cur] == -1)
        {
            ans = i + 1;
            // std::cout << ans << " ";
        }
    }
    return ans;
}

int main()
{
    int len;
    int num;
    std::string str;
    std::cin >> len >> num;
    std::cin >> str;
    for (int i = 0; i < num; i++)
    {
        std::cin >> strs[i];
        insert(strs[i]);
    }
    build();
    find(str);
    for (int i = 0; i < num; i++)
    {
        std::cout << Find(strs[i]) << std::endl;
    }
    return 0;
}
