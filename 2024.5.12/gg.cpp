#include <iostream>
#include <map>
#include <queue>

using namespace std;

int k;
int n;

void bfs()
{
    map< int, bool > m;
    queue< pair< int, int > > q;
    q.push({n, 0});
    m[n] = 1;
    while (1)
    {
        pair< int, int > h = q.front();
        q.pop();
        if (h.first == k)
        {
            cout << h.second;
            return;
        }
        if (h.first < k)
        {
            if (!m[h.first * 2])
            {
                q.push({h.first * 2, h.second + 1});
                m[h.first * 2] = 1;
            }
            if (!m[h.first + 1])
            {
                q.push({h.first + 1, h.second + 1});
                m[h.first + 1] = 1;
            }
            if (!m[h.first - 1])
            {
                q.push({h.first - 1, h.second + 1});
                m[h.first - 1] = 1;
            }
        } else
        {
            if (!m[h.first - 1])
            {
                q.push({h.first - 1, h.second + 1});
                m[h.first - 1] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    bfs();
    return 0;
}
