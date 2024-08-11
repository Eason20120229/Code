#include <algorithm>
#include <iostream>
#define N 5001
#define M 200001

struct node
{
    int start;
    int end;
    int value;
} edges[M];

int num;
int ecnt;
int icnt;
int cnt;
int fath[N];

int find(int cur)
{
    if (fath[cur] == cur)
    {
        return cur;
    }
    return fath[cur] = find(fath[cur]);
}

void unset(int cur1, int cur2)
{
    int fcur1 = find(cur1);
    int fcur2 = find(cur2);
    if (fcur1 == fcur2)
    {
        return;
    }
    fath[fcur1] = fcur2;
}

void addEdge(int start, int end, int value)
{
    ecnt++;
    edges[ecnt].start = start;
    edges[ecnt].end = end;
    edges[ecnt].value = value;
}

bool cmp(node one, node two)
{
    return one.value < two.value;
}

int Kruskal()
{
    for (int i = 1; i <= num; i++)
    {
        fath[i] = i;
    }
    std::sort(edges + 1, edges + icnt + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= ecnt; i++)
    {
        int cur1 = edges[i].start;
        int cur2 = edges[i].end;
        cur1 = find(cur1);
        cur2 = find(cur2);
        if (cur1 != cur2)
        {
            ans += edges[i].value;
            unset(cur1, cur2);
            cnt++;
        }
    }
    return ans;
}

int main()
{
    std::cin >> num >> icnt;
    for (int i = 1; i <= icnt; i++)
    {
        int start;
        int end;
        int value;
        std::cin >> start >> end >> value;
        addEdge(start, end, value);
    }
    int ans = Kruskal();
    if (cnt < num - 1)
    {
        std::cout << "orz";
    } else
    {
        std::cout << ans;
    }
    return 0;
}
