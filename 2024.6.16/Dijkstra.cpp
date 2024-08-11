#include <iostream>
#define N   10001
#define INF 0x7fffff

int arr[N][N];
int dis[N];
bool book[N];

auto main() -> int
{
    int num;
    int cnt;
    int cur;
    std::cin >> num >> cnt >> cur;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i != j)
            {
                arr[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int one;
        int two;
        int vvv;
        std::cin >> one >> two >> vvv;
        arr[one][two] = std::min(vvv, arr[one][two]);
        arr[two][one] = std::min(vvv, arr[two][one]);
    }
    dis[cur] = 0;
    int uuu = cur;
    for(int j = 1;j < num;j++)
    {
        int tmp = INF;
        for (int i = 1; i <= num; i++)
        {
            if (arr[uuu][i] < INF && i != uuu)
            {
                dis[i] = std::min(dis[uuu] + arr[uuu][i], dis[i]);
            }
        }
        book[uuu] = true;
        for (int i = 1; i <= num; i++)
        {
            if (!book[i] && dis[i] < INF)
            {
                tmp = i;
            }
        }
        uuu = tmp;
    }
    for (int i = 1; i <= num; i++)
    {
        std::cout << dis[i] << " ";
    }
    return 0;
}
