#include <cstdint>
#include <iostream>

using namespace std;

int64_t dp[1000001] = {0, 1, 1};

int64_t func(int iint)
{
    if (iint <= 2)
    {
        return dp[iint];
    }
    if (dp[iint] != 0)
    {
        dp[iint] = func(iint - 1) + func(iint - 2);
    }
    return dp[iint];
}

int main()
{
    int num;
    cin >> num;
    cout << func(num);
    return 0;
}
