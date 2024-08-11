/* 郑廷轩 */
#include <iostream>
#define N   10001
#define INF 0x7fffff

int arr[N][N];
int dis[N];
bool book[N];

auto main() -> int
{
    int num;
    int cnt;
    int cur;
    std::cin >> num >> cnt >> cur;
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
    for (int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int one;
        int two;
        int vvv;
        std::cin >> one >> two >> vvv;
        arr[one][two] = vvv;
        arr[two][one] = vvv;
    }
    dis[cur] = 0;
    int uuu = cur;
    int i = 1;
    while (cnt--)
    {  //?
        int tmp;
        std::cout << i++;
        std::cout << "u=" << uuu << " ";
        for (int i = 1; i <= num; i++)
        {
            if (arr[uuu][i] < INF && i != uuu)
            {
                dis[i] = std::min(dis[uuu] + arr[uuu][i], dis[i]);
                std::cout << "dis[" << i << "]=" << dis[i] << " ";
            }
        }
        book[uuu] = true;
        int mi = INF;
        for (int i = 1; i <= num; i++)
        {
            //            std::cout<<uuu<<"-->"<<i<<" 边权:"<<arr[uuu][i];
            if (!book[i] && arr[uuu][i] < mi)
            {
                //                std::cout<<"wow";
                mi = arr[uuu][i];
                tmp = i;
                //                std::cout<<" 找到了"<<mi<<" "<<i<<"\n";
            }
        }
        uuu = tmp;
        std::cout << "\n";
    }
    for (int i = 1; i <= num; i++)
    {
        std::cout << dis[i] << " ";
    }
    return 0;
}
