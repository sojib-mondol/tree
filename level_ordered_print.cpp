//               root
//                10
//         a- 20      30 -b
//      c- 40   90 -h      50 -d
//        e- 60  100  f- 70   80 -g
//                 i

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void level_ordered(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotio ja kaj ache
        cout << f->val << " ";

        // 3. tar children gulo ke rakha

        if (f->right)
            q.push(f->right);
        if (f->left)
            q.push(f->left);
    }
}

int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    // connection
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->left = d;
    d->left = f;
    d->right = g;
    h->right = i;

    level_ordered(root);

    return 0;
}