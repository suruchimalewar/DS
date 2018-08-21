#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

void printLeft(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left)
    {
        cout << root->data << " ";
        printLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printLeft(root->right);
    }
}

void PrintRight(Node *root)
{
    if (root == nullptr)
        return;

    if (root->right)
    {
        PrintRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        PrintRight(root->left);
        cout << root->data << " ";
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
    if (root == nullptr)
        return;
    printLeft(root);

    printLeaf(root->left);
    printLeaf(root->right);

    PrintRight(root);
}
int main()
{
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    cout << "Given a binary tree, print all root-to-leaf paths  \n";
    BoundryLevelPrint(root);
    return 0;
}