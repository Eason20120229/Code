#include <iostream>
#define N 100001
#define M 200002
using std::cin, std::cout;

int cint = 0;
int num;
int cnt;
int edges[N][N];
int vis[N];
int out[M];

void find(int inum)
{
    for (int j = 1; j <= num; j++)
    {
        if (edges[inum][j] > 0)
        {
            edges[inum][j]--;
            edges[j][inum]--;
            find(j);
        }
    }
    vis[++cint] = inum;
}

auto main() -> int
{
    cin >> num >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        edges[start][end]++;
        edges[end][start]++;
        out[start]++;
        out[end]++;
    }
    int one = 1;
    int kun = 0;
    for (int i = 1; i <= num; i++)
    {
        if (out[i] % 2 != 0)
        {
            one = i;
            kun++;
        }
    }
    if (kun != 2 && kun != 0)
    {
        cout << "No";
    } else
    {
        cint = 0;
        find(one);
        for (int i = 1; i <= cint; i++)
        {
            cout << vis[i] << " ";
        }
    }
    return 0;
}
