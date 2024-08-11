#include <iostream>

using namespace std;

int main()
{
    int id = 0;
    int m = 0;
    for (int i = 1; i <= 7; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a + b > m)
        {
            id = i;
            m = a + b;
        }
    }
    if (m > 8)
        cout << id;
    else
        cout << 0;
    return 0;
}
