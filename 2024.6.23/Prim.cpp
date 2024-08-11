#include <iostream>
#define N   101
#define INF 0x7fff

int num, edge;
int app[N][N];
int minn[N];

void init()
{
    int start;
    int end;
    int value;
    std::cin >> num >> edge;
    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j <= num; j++)
        {
            if (i != j)
            {
                app[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= edge; i++)
    {
        std::cin >> start >> end >> value;
        app[start][end] = app[end][start] = value;
    }
}

void prim(int start)
{
    int ans = 0;
    int mini = INF;
    int cur = 0;
    for (int i = 1; i <= num; i++)
    {
        minn[i] = app[start][i];
    }
    for (int i = 1; i < num; i++)
    {
        mini = INF;
        for (int j = 1; j <= num; j++)
        {
            if (minn[j] != 0 && minn[j] < mini)
            {
                mini = minn[j];
                cur = j;
            }
        }
        minn[cur] = 0;
        ans += mini;
        for (int j = 1; j <= num; j++)
        {
            if (minn[j] > app[cur][j])
            {
                minn[j] = app[cur][j];
            }
        }
    }
    std::cout << ans << std::endl;
}

auto main() -> int
{
    init();
    prim(1);
    return 0;
}
