#include <iostream>
#include <queue>
#include <string>
#define NUM 26
#define N   500001
#define ULL unsigned long long

int idx = 0;
int chr[N][NUM];
int fail[N];
int cnt[N];

void insert(std::string patt)
{
    int cur = 0;
    ULL len = patt.size();
    for (int i = 0; i < len; i++)
    {
        if (chr[cur][patt[i] - 'a'] == 0)
        {
            chr[cur][patt[i] - 'a'] = ++idx;
        }
        cur = chr[cur][patt[i] - 'a'];
    }
    cnt[cur]++;
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

int find(std::string str)
{
    int icnt = 0;
    int cur = 0;
    for (int k = 0; k < str.size(); k++)
    {
        cur = chr[cur][str[k] - 'a'];
        for (int j = cur; j != 0 && cnt[j] != -1; j = fail[j])
        {
            icnt += cnt[j];
            cnt[j] = -1;
        }
    }
    return icnt;
}

int main()
{
    int num;
    std::string str;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        insert(tmp);
    }
    build();
    std::cin >> str;
    std::cout << find(str) << std::endl;
    return 0;
}
