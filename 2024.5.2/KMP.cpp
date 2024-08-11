#include <bits/stdc++.h>
typedef unsigned long long ULL;
using namespace std;
vector< ULL > build_next(string patt)
{
    vector< ULL > next{0};  // 初始化next数组
    ULL prefix_len = 0;     // 当前共同前后缀的长度
    ULL i = 1;
    while (i < patt.length())
    {
        // for (auto tmp : next)cout << tmp << " ";
        if (patt[prefix_len] == patt[i])
        {
            prefix_len++;
            next.push_back(prefix_len);
            i++;
        } else
        {
            if (prefix_len == 0)
            {
                next.push_back(prefix_len);
                i++;
            } else
            {
                prefix_len = next[prefix_len - 1];
            }
        }
    }
    return next;
}
pair< ULL, bool > kmp_search(string text, string patt)
{
    vector< ULL > next = build_next(patt);  // 假设我们已经找到了next数组
    // for (ULL i = 0; i < patt.size(); i++)
    //     cout << i << ":" << next[i] << "  ";
    ULL i = 0;  // 主串中的指针
    ULL j = 0;  // 子串中的指针
    cout << endl;
    while (i < text.length())
    {
        if (text[i] == patt[j])
        {  // 匹配成功，指针后移
            i++;
            j++;
        } else if (j > 0)
        {  // 字符匹配失败，根据 next 跳过子串前面的一些字符
            j = next[j - 1];
        } else
        {  // 子串第一个字符就失败了
            i++;
        }
        if (j == patt.length())
        {
            return {i - j, 0};  // 匹配成功，返回定位
        }
    }
    return {0, 1};
}
int main()
{
    pair< ULL, bool > i = kmp_search("bbbbccbbbbb", "bbbbc");
    if (i.second)
        cout << -1;
    else
        cout << i.first;
    return 0;
}
