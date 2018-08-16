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
void printLeft(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        if (root->left)
        {
            cout << root->data << " ";
            printLeft(root->left);
        }
        else if (root->right)
        {
            cout << root->data;
            printLeft(root->right);
        }
    }
}

void PrintRight(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        if (root->right)
        {
            cout << root->data << " ";
            printLeft(root->right);
        }
        else if (root->left)
        {
            cout << root->data;
            printLeft(root->left);
        }
    }
}

void printLeaf(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        cout << root->data << " ";
    printLeaf(root->left);

    printLeaf(root->right);
}
void BoundryLevelPrint(Node *root)
{
    printf("%d ", root->data);
    printLeft(root->left);
    printLeaf(root);
    PrintRight(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Given a binary tree, print all root-to-leaf paths  \n";
    BoundryLevelPrint(root);
}