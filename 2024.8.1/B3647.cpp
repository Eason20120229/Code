#include <iostream>
#define N   101
#define M   4501
#define INF 0x3f3f3f3f

struct edge
{
    int next;
    int end;
    int value;
};

int num;
int cnt;
int ecnt;
int head[N];
edge eds[M];
int dis[N];
bool vis[N];

void init(int num, int cnt)
{
    for (int i = 1; i <= num; i++)
    {
        head[i] = -1;
    }
    for (int i = 1; i <= cnt; i++)
    {
        eds[i].next = -1;
    }
}

void add(int start, int end, int value)
{
    int idt = ++ecnt;
    eds[idt].value = value;
    eds[idt].end = end;
    eds[idt].next = head[start];
    head[start] = idt;
}

void dij(int start)
{
    for (int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    for (int i = 1; i <= num; i++)
    {
        vis[i] = false;
    }
    dis[start] = 0;
    for (int i = 1; i <= num; i++)
    {
        int tmp = -1;
        for (int j = 1; j <= num; j++)
        {
            if (!vis[j] && (tmp == -1 || dis[j] < dis[tmp]))
            {
                tmp = j;
            }
        }
        // std::cout << "<" << tmp << std::endl;
        vis[tmp] = true;
        for (int j = head[tmp]; j != -1; j = eds[j].next)
        {
            dis[eds[j].end] =
                std::min(dis[eds[j].end], dis[tmp] + eds[j].value);
        }
    }
}

auto main() -> int
{
    std::cin >> num >> cnt;
    init(num, cnt * 4);
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        int value;
        std::cin >> start >> end >> value;
        add(start, end, value);
        std::swap(start, end);
        add(start, end, value);
    }
    for (int i = 1; i <= num; i++)
    {
        dij(i);
        for (int j = 1; j <= num; j++)
        {
            std::cout << dis[j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
