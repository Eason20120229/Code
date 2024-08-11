#include <iostream>
#include <queue>
#define int long long
#define N   20001
#define M   500001
#define INF 0x7fffffff

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
edge edge[M];
int dis[N];
bool vis[N];
int cnte[N];

void init(int num, int cnt)
{
    for (int i = 1; i <= num; i++)
    {
        head[i] = -1;
    }
    for (int i = 1; i <= cnt; i++)
    {
        edge[i].next = -1;
    }
}

void add(int start, int end, int value)
{
    int idt = ++ecnt;
    edge[idt].value = value;
    edge[idt].end = end;
    edge[idt].next = head[start];
    head[start] = idt;
}

bool spfa(int s)
{
    for (int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    std::queue< int > que;
    que.push(s);
    dis[s] = 0;
    vis[s] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        cnte[cur]++;
        if (cnte[cur] > num - 1)
        {
            return false;
        }
        if (dis[cur] != INF)
        {
            for (int nxt = head[cur]; nxt != -1; nxt = edge[nxt].next)
            {
                if (dis[edge[nxt].end] > dis[cur] + edge[nxt].value)
                {
                    dis[edge[nxt].end] = dis[cur] + edge[nxt].value;
                    if (!vis[edge[nxt].end])
                    {
                        que.push(edge[nxt].end);
                    }
                    vis[edge[nxt].end] = true;
                }
            }
        }
    }
    return true;
}

auto main() -> signed
{
    int s;
    std::cin >> num >> cnt >> s;
    init(num, cnt);
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        int value;
        std::cin >> start >> end >> value;
        add(start, end, value);
    }
    if (spfa(s))
    {
        for (int i = 1; i <= num; i++)
        {
            std::cout << dis[i] << " ";
        }
    } else
    {
        std::cout << "impossible";
    }
    return 0;
}
