#include <algorithm>
#include <iostream>
#define M 2001

struct node
{
    int start;
    int end;
    int value;
} edge[M];

int num;
int cnt;
int ecnt;
int fat[M];

void add(int start, int end, int value)
{
    ecnt++;
    edge[ecnt].start = start;
    edge[ecnt].end = end;
    edge[ecnt].value = value;
}

auto cmp(node one, node two) -> bool
{
    return one.value < two.value;
}

auto find(int cur) -> int
{
    // std::cout << cur << "-" << fat[cur] << " ";
    return cur == fat[cur] ? cur : fat[cur] = find(fat[cur]);
}

void init(int num)
{
    for (int i = 1; i <= num; i++)
    {
        fat[i] = i;
    }
}

void merge(int one, int two)
{
    one = find(one);
    two = find(two);
    if (one != two)
    {
        fat[one] = two;
    }
}

auto main() -> int
{
    std::cin >> num >> cnt;
    init(num);
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
    int ans = 0;
    std::sort(edge + 1, edge + ecnt + 1, cmp);
    for (int i = 1, j = 1; i < ecnt && j < num; i++)
    {
        if (find(edge[i].start) == find(edge[i].end))
        {
            continue;
        }
        merge(edge[i].start, edge[i].end);
        ans += edge[i].value;
        j++;
    }
    std::cout << ans;
    return 0;
}
