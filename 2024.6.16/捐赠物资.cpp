#include <iostream>
#define N   10001
#define INF 0x7ffffff

int arr[N][N];

auto main() -> int
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int one;
        int two;
        int vvv = 1;
        std::cin >> one >> two;
        arr[one][two] = std::max(vvv, arr[one][two]);
        arr[two][one] = std::max(vvv, arr[two][one]);
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            for (int k = 1; k <= num; k++)
            {
                int tmp = arr[j][i] * arr[i][k];
                if (tmp > arr[j][k])
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
