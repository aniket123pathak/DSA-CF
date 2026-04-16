#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int data, height;
    Node *left, *right;
};
int height(Node *n)
{
    return n ? n->height : 0;
}
Node *newNode(int x)
{
    Node *n = new Node();
    n->data = x;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}
int getBalance(Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
Node *insert(Node *root, int key)
{
    if (!root)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBalance(root);
    if (bf > 1 && key < root->left->data)
        return rightRotate(root); // LL
    if (bf < -1 && key > root->right->data)
        return leftRotate(root); // RR
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root); // LR
    }
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root); // RL
    }
    return root;
}
bool search(Node *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}
int main()
{
    Node *root = NULL;
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        root = insert(root, x);
    }
    cin >> x;
    cout << (search(root, x) ? "Found" : "Not Found");
    return 0;
}