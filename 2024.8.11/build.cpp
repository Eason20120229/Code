#include <iostream>

using namespace std;

int cnt;
struct node
{
    char key;
    int left;
    int right;
} tree[10001];

int build()
{
    char chr;
    cin >> chr;
    if (chr == '#')
    {
        return 0;
    }
    int root = ++cnt;
    tree[root].key = chr;
    tree[root].left = build();
    tree[root].right = build();
    return root;
}

int main()
{
    build();
    for (int i = 1; i <= cnt; i++)
    {
        std::cout << i << " " << tree[i].key << " " << tree[i].left << " "
                  << tree[i].right << std::endl;
    }
    return 0;
}
