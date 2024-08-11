#include <bits/stdc++.h>
#define N 7

int num;
int shu[N];
int out[N];
bool flag[N];

void dfs(int step)
{
    if (step == num)
    {
        for (int i = 0; i < num; i++)
        {
            std::cout << out[i] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < num; i++)
    {
        if (!flag[i])
        {
            flag[i] = true;
            out[step] = shu[i];
            dfs(step + 1);
            flag[i] = false;
        }
    }
}

int main()
{
    std::freopen("10843.txt", "w", stdout);
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::cin >> shu[i];
    }
    dfs(0);
    return 0;
}
