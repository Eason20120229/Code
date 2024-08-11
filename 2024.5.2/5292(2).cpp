#include <iostream>
#include <string>

using namespace std;

string u[7];
string a = "0";
int sum[301][301];
int dp[301][301];
int p, k, s;

int findStr(int l, int r)
{
    string t = a.substr(l, r - l + 1);
    for (int i = 1; i <= s; i++)
    {
        if (t.find(u[i]) == 0)
            return 1;
    }
    return 0;
}

void cntNum()
{
    for (int i = a.size() - 1; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            sum[j][i] = sum[j + 1][i];
            if (findStr(j, i))
                sum[j][i]++;
        }
    }
}

int main()
{
    string c;
    cin >> p >> k;
    while (p--)
    {
        cin >> c;
        a += c;
    }
    cin >> s;
    for (int i = 1; i <= s; i++)
    {
        cin >> u[i];
    }
    // 初始化
    cntNum();
    // dp初始化边界
    dp[0][0] = 0;
    // 前i个分i块
    for (int i = 1; i <= k; i++)
        dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    // 前i个分1块
    for (int i = 1; i <= a.size() - 1; i++)
        dp[i][1] = sum[1][i];
    for (int i = 1; i <= a.size() - 1; i++)
        for (int j = 1; j <= k; j++)
            // l 边界点
            for (int l = j; l < i; l++)
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + sum[l + 1][i]);
    cout << dp[a.size() - 1][k];
    return 0;
}
