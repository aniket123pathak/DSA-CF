#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

static int index = -1;

Node *buildTree(vector<int> &nodes)
{
    index++;
    if (nodes[index] == -1 || index >= nodes.size())
    {
        return NULL;
    }

    Node *currRoot = new Node(nodes[index]);
    currRoot->left = buildTree(nodes);
    currRoot->right = buildTree(nodes);

    return currRoot;
}

void preOrderTraversal(Node *root)
{
    // Root
    // LeftSubtree
    // RightSubtree

    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // LeftSubtree
    // root
    // RightSubtree

    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // LeftSubtree
    // RightSubtree
    // root

    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *currRoot = q.front();
        q.pop();

        if (currRoot == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else
        {
            cout << currRoot->data << " ";
            if (currRoot->left != NULL)
            {
                q.push(currRoot->left);
            }

            if (currRoot->right != NULL)
            {
                q.push(currRoot->right);
            }
        }
    }
}

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int nodeCount(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftNodes = nodeCount(root->left);
    int rightNodes = nodeCount(root->right);

    return leftNodes + rightNodes + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return root->data + leftSum + rightSum;
}

int main()
{
    vector<int> nodes = {1, 2, 3, -1, -1, 4, -1, 5, 6, 7, 8, -1, -1, 9, 10, 11, 12, -1, 99, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(nodes);
    cout << "Preorder TraverSal : ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Inorder TraverSal : ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Postorder TraverSal : ";
    postOrderTraversal(root);
    cout << endl;
    cout << "Levelorder TraverSal : \n";
    levelOrderTraversal(root);
    cout << endl;
    int height = heightOfTree(root);
    cout << "Height Of the Tree is : " << height << endl;
    int noOfNodes = nodeCount(root);
    cout << "Number of Nodes in tree : " << noOfNodes << endl;
    int sumOfNode = sumOfNodes(root);
    cout << "Sum of Nodes in tree : " << sumOfNode << endl;
    return 0;
}
