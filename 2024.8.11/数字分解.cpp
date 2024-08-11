#include <iostream>
#define N 101

int num;
int cur;
int arr[N];

void dfs(int cnt, int last)
{
    if (cur == 0)
    {
        std::cout << num << "=";
        for (int i = 0; i < cnt - 1; i++)
        {
            std::cout << arr[i] << "+";
        }
        std::cout << arr[cnt - 1] << std::endl;
        return;
    }
    for (int i = std::min(last, cur); i > 0; i--)
    {
        cur -= i;
        arr[cnt] = i;
        dfs(cnt + 1, i);
        cur += i;
    }
}

int main()
{
    std::cin >> num;
    cur = num;
    dfs(0, num);
    return 0;
}
