#include <iostream>

using namespace std;

int cnt;
struct node
{
    char key;
    int left;
    int right;
} tree[10001];

void inorder(int root)
{
    if (root != 0)
    {
        inorder(tree[root].right);
        std::cout << tree[root].key << ' ';
        inorder(tree[root].left);
    }
}

int main()
{
    bool isch[10001];
    std::cin >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int tmp;
        std::cin >> tmp;
        std::cin >> tree[tmp].key >> tree[tmp].left >> tree[tmp].right;
        isch[tree[tmp].left] = isch[tree[tmp].right] = true;
    }
    int root = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (!isch[i])
        {
            root = i;
            break;
        }
    }
    inorder(root);
    return 0;
}
