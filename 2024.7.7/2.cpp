#include <iostream>

int tmpx;
int tmpy;
bool flag;
int move[8][2] = {{1, 2},  {1, -2},  {2, 1},   {2, -1},
                  {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};

void dfs(int x, int y, int step)
{
    if (step > 3)
    {
        return;
    }
    if (step <= 3 && x == tmpx && y == tmpy)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        dfs(x + move[i][0], y + move[i][1], step + 1);
    }
}

int main()
{
    int cnt;
    std::cin >> cnt;
    while (cnt-- != 0)
    {
        flag = false;
        std::cin >> tmpx >> tmpy;
        dfs(0, 0, 0);
        if (flag)
        {
            std::cout << "YES";
        } else
        {
            std::cout << "NO";
        }
    }
    return 0;
}
