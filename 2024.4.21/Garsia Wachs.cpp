#include <bits/stdc++.h>

using namespace std;

vector< int > a;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a.push_back(0);
        cin >> a[i];
    }
    while (a.size() != 1)
    {
        int k, t, m;
        for (k = 1; k < a.size() - 1; k++)
        {
            if (a[k - 1] <= a[k + 1])
                break;
            if (k == a.size() - 2)
                break;
        }
        t = a[k - 1] + a[k];
        a.erase(a.begin() + k - 1, a.begin() + k + 1);
        for (m = 0; m < a.size() && a[m] > t; m++)
            ;
        a.insert(a.begin() + m, t);
        ans += t;
        for (k = 1; k < a.size(); k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
    cout << ans;
    return 0;
}
