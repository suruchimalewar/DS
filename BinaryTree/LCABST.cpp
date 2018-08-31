#include "BinaryTree.h"
#include "BST.h"
#include <iostream>

using namespace std;

Node *lowestCommonAcc(Node *root, int val1, int val2)
{
    if (root->data > max(val1, val2))
    {
        return lowestCommonAcc(root->left, val1, val2);
    }
    if (root->data < min(val1, val2))
    {
        return lowestCommonAcc(root->right, val1, val2);
    }
    else
        return root;
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

    Inorder(root);
    Node *value = lowestCommonAcc(root, 21, 15);
    if (value != nullptr)
        cout << "LCA is" << (value->data);
    return 0;
    cout << endl;

    return 0;
}
