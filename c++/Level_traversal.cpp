#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
typedef struct node
{
    int pt;
    struct node *left;
    struct node *right;
} node;
using namespace std;
class tree
{
public:
    tree() = default;
    ~tree() = default;
    node *create()
    {
        char ch;
        ch = getchar();
        if (ch == '#')
            return NULL;
        node *t = new node;
        t->pt = ch;
        t->left = create();
        t->right = create();
        return t;
    }
    void cengci(node *root)
    {
        queue<node *> s;
        s.push(root);
        while (!s.empty())
        {
            printf("%c", s.front()->pt);
            if (s.front()->left != nullptr)
                s.push(s.front()->left);
            if (s.front()->right != nullptr)
                s.push(s.front()->right);
            s.pop();
        }
        return;
    }
};
int main()
{
    tree s;
    node *t = s.create();
    s.cengci(t);
    return 0;
}