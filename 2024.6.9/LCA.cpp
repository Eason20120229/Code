#include <iostream>
#include <vector>
#define N   500001
#define NUM 21

int num;
int cnt;
int root;
std::vector< int > edge[N];
int dep[N], fat[N][NUM];

void dfs(int son, int fath)
{
    dep[son] = dep[fath] + 1;
    fat[son][0] = fath;
    for (int i = 1; i <= NUM - 1; i++)
    {
        fat[son][i] = fat[fat[son][i - 1]][i - 1];
    }
    for (int sonn : edge[son])
    {
        if (sonn != fath)
        {
            dfs(sonn, son);
        }
    }
}

auto lca(int one, int two) -> int
{
    if (dep[one] < dep[two])
    {
        std::swap(one, two);
    }
    for (int i = NUM - 1; i >= 0; i--)
    {
        if (dep[fat[one][i]] >= dep[two])
        {
            one = fat[one][i];
        }
    }
    if (one == two)
    {
        return one;
    }
    for (int i = NUM - 1; i >= 0; i--)
    {
        if (fat[one][i] != fat[two][i])
        {
            one = fat[one][i];
            two = fat[two][i];
        }
    }
    return fat[one][0];
}
auto main() -> int
{
    scanf("%d %d %d", &num, &cnt, &root);
    for (int i = 1; i < num; i++)
    {
        int one;
        int two;
        scanf("%d %d", &one, &two);
        edge[one].push_back(two);
        edge[two].push_back(one);
    }
    dfs(root, 0);
    while (cnt-- != 0)
    {
        int one;
        int two;
        scanf("%d %d", &one, &two);
        std::cout << lca(one, two) << std::endl;
    }
    return 0;
}
