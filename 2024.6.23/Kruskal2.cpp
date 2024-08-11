#include <algorithm>
#include <iostream>
#define N 2001
#define M 100001

struct edge
{
    int start;
    int end;
    int value;
} edges[M];

int num;
int cnt;

bool cmp(edge one, edge two)
{
    return one.value < two.value;
}

void Kruskal()
{
    std::sort(edges + 1, edges + cnt + 1);
}

auto main() -> int
{
    std::cin >> num >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        std::cin >> edges[i].start >> edges[i].end >> edges[i].value;
    }
    return 0;
}
