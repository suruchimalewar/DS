#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node() : left(nullptr), right(nullptr)
    {
    }
    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};

int heightOfBinaryTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int l = heightOfBinaryTree(root->left);
        int r = heightOfBinaryTree(root->right);

        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}
void printPerGivenLevel(Node *root, int i)
{
    if (root == nullptr)
        return;

    if (i == 1)
        cout << root->data << " ";

    else if (i > 1)
    {
        printPerGivenLevel(root->left, i - 1);
        printPerGivenLevel(root->right, i - 1);
    }
}
void printLevelOrder(Node *root)
{
    int height = heightOfBinaryTree(root);

    for (int i = 1; i < height; ++i)
    {
        printPerGivenLevel(root, i);
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(9);

    cout << "Level order traversal of given Binary tree is  \n";
    printLevelOrder(root);
}