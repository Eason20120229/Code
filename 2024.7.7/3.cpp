#include <algorithm>
#include <iostream>
#define N 16

int sign[N];
int nums[N];
int cnum;
int csign;

bool cmp(int a, int b)
{
    return a > b;
}

auto main() -> int
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        char tmp;
        std::cin >> tmp;
        while (tmp == ' ')
        {
            std::cin >> tmp;
        }
        if ('0' <= tmp && '9' >= tmp)
        {
            nums[++cnum] = tmp - '0';
        } else if (tmp == '+')
        {
            sign[++csign] = 0;
        } else if (tmp == '-')
        {
            sign[++csign] = 1;
        }
    }
    int i = 0;
    int minn = 0;
    int maxx = 0;
    std::sort(nums + 1, nums + 1 + cnum);
    std::sort(sign + 1, sign + 1 + csign);
    for (i = 1; i <= csign; i++)
    {
        if (sign[i] == 0)
        {
            i--;
            break;
        }
        maxx -= nums[i];
    }
    int tmp1 = csign - i;
    int tmp2 = cnum - i;
    int tmp3 = tmp2 - tmp1 - 1;
    int tmp4 = 0;
    for (i = 0; i < tmp3; i++)
    {
        tmp4 = tmp4 * 10 + nums[cnum - i];
    }
    maxx += tmp4;
    tmp2 = cnum - i;
    for (; i < tmp2; i++)
    {
        maxx += nums[cnum - i];
    }
    std::cout << maxx << " ";

    std::sort(nums + 1, nums + 1 + cnum, cmp);
    std::sort(sign + 1, sign + 1 + csign, cmp);
    for (i = 1; i <= csign; i++)
    {
        if (sign[i] == 1)
        {
            i--;
            break;
        }
        minn += nums[i];
    }
    tmp1 = csign - i;
    tmp2 = cnum - i;
    tmp3 = tmp2 - tmp1 - 1;
    tmp4 = 0;
    for (i = 0; i < tmp3; i++)
    {
        tmp4 = tmp4 * 10 + nums[cnum - i];
    }
    minn -= tmp4;
    tmp2 = cnum - i;
    for (; i < tmp2; i++)
    {
        minn += nums[cnum - i];
    }
    std::cout << minn;
    return 0;
}
