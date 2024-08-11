#include <cstring>
#include <iostream>
#define N   510
#define INF 0x3f3f3f3f

int num, cnt, start, k, end;
int dis[N];
int graph[N][N];
int pre[N];
int arr[N];
bool book[N];
bool a[N][N];
bool b[N];

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
        for (int i = 1; i <= k; i++)
        {
            b[i] = false;
        }
        for (int i = pre[tmp]; i != 0; i = pre[i])
        {
            b[arr[i]] = true;
        }
        b[arr[tmp]] = true;
        book[tmp] = true;
        for (int j = 1; j <= num; j++)
        {
            if (dis[j] > dis[tmp] + graph[tmp][j] && !book[j])
            {
                bool flag = true;
                for (int i = 1; i <= k; i++)
                {
                    if (a[arr[j]][i] && b[i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    dis[j] = dis[tmp] + graph[tmp][j];
                    pre[j] = tmp;
                }
            }
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
    std::cin >> num >> k >> cnt >> start >> end;
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
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int tmp;
            std::cin >> tmp;
            if (tmp == 1 || i == j)
            {
                a[i][j] = true;
            }
        }
    }
    while (cnt-- != 0)
    {
        int start;
        int end;
        int value;
        scanf("%d%d%d", &start, &end, &value);
        graph[end][start] = graph[start][end] =
            std::min(graph[start][end], value);
    }
    std::cout << dij(start, end);
    return 0;
}
