#include "BinaryTree.h"
#include "BST.h"
#include <iostream>

using namespace std;
Node *FindMInONRight(Node *root)
{

    while (root != nullptr && root->left != nullptr)

        root = root->left;
    return root;
}
Node *DeleteBST(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->data > val)
        root->left = DeleteBST(root->left, val);
    else if (root->data < val)
        root->right = DeleteBST(root->right, val);
    else
    {
        if (root->left == nullptr)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        if (root->right == nullptr)
        {
            Node *t = root->left;
            delete root;
            return t;
        }

        Node *t = FindMInONRight(root->right);
        root->data = t->data;

        root->right = DeleteBST(root->right, t->data);
    }
}
int main()
{
    // Variation 2
    Node *root = NULL;
    for (int i = 0; i < 10; ++i)
    {
        BSTInsert(root, rand() % 50);
    }

    DrawBinaryTree(root);
    DeleteBST(root, 33);
    DrawBinaryTree(root);
    cout << endl;

    return 0;
}
