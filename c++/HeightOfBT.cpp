//The height of the binary tree

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <deque>

typedef struct node
{
    int pt;
    struct node *left;
    struct node *right;
}node, *ptnode;

using namespace std;

class tree {
public:
        tree() = default;
        ~tree() = default;

        ptnode create() 
        {
            char ch;

            ch = getchar();
            if (ch == '#')
                return NULL;
            ptnode t = new node;
            t->pt = ch;
            t->left = create();
            t->right = create();

            return t;
        }

        int high(ptnode root)
        {
            int a, b;

            if(root == nullptr)
                return 0;
            a = high(root->left);
            b = high(root->right);

            return a > b ? a + 1 : b + 1; 
        }

private:

};

int main()
{
    tree s;
    ptnode t = s.create();
    cout << s.high(t);

    return 0;
}