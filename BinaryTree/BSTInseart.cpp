#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

Node *Insert(Node *root, int key)
{
    if (root == nullptr)
        return (new Node(key));

    if (root->data > key)
    {
        root->left = Insert(root->left, key);
    }
    else
    {
        root->right = Insert(root->right, key);
    }
    return root;
}
int main()
{
    struct Node *root = NULL;
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    //root->left->right->left = new Node(9);
    DrawBinaryTree(root);
}