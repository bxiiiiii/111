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

    void count(ptnode root)
    {
        int a = 0, b = 0,c = 0;
        stack<ptnode> s;
        ptnode t=root;
        vector<char> pt;

        while (t != nullptr || !s.empty())
        {
            while(t != nullptr)
            {   
                if(t->left && t->right)
                    a++;
                else if(t->left || t->right)
                    b++;
                else {
                    c++;
                    pt.push_back(t->pt);
                }

                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            t = t->right;
        }

        cout << c << " " << b << " " << a << endl;
        for(auto i : pt)
            cout << i;
    }
};

int main()
{
    tree s;
    ptnode t = s.create();
    s.count(t);
    return 0;
}