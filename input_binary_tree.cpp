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

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // 1. ber kore ano
        Node *p = q.front();
        q.pop();

        // 2. jabotio ja kaj ache
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        // connection
        p->left = myLeft;
        p->right = myRight;

        // children gula push koro
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
}

void level_ordered(Node *root)
{
    if (root == NULL)
    {
        cout << "tree empty\n";
        return;
    }
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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = input_tree();
    level_ordered(root);
    return 0;
}