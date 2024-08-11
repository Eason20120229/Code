#include <iostream>
#define N   10001
#define INF 0x7ffffff

int arr[N][N];

auto main() -> int
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
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
    for (int i = 1; i <= cnt; i++)
    {
        int one;
        int two;
        int vvv;
        std::cin >> one >> two >> vvv;
        arr[one][two] = std::min(vvv, arr[one][two]);
        arr[two][one] = std::min(vvv, arr[two][one]);
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            for (int k = 1; k <= num; k++)
            {
                int tmp = arr[j][i] + arr[i][k];
                if (tmp < arr[j][k])
                {
                    arr[j][k] = tmp;
                }
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
