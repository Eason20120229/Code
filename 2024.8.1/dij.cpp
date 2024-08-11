#include <cstring>
#include <iostream>
#define N   510
#define INF 0x3f3f3f3f

int num, cnt, start;
int dis[N];
int graph[N][N];
bool book[N];

auto dij(int start, int end) -> int
{
    for (int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    dis[start] = 0;
    for (int i = 1; i <= num; i++)
    {
        int tmp = -1;
        for (int j = 1; j <= num; j++)
        {
            if (!book[j] && (tmp == -1 || dis[tmp] > dis[j]))
            {
                tmp = j;
            }
        }
        book[tmp] = true;
        for (int j = 1; j <= num; j++)
        {
            dis[j] = std::min(dis[j], dis[tmp] + graph[tmp][j]);
        }
    }
    if (dis[end] == INF)
    {
        return -1;
    }
    return dis[end];
}

auto main() -> int
{
    std::cin >> num >> cnt >> start;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i != j)
            {
                graph[i][j] = INF;
            }
        }
    }
    while (cnt-- != 0)
    {
        int start;
        int end;
        int value;
        scanf("%d%d%d", &start, &end, &value);
        graph[start][end] = value;
    }
    std::cout << dij(start, num);
    return 0;
}
