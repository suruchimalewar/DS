#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;
Node *lowestCommonAcc(Node *root, int val1, int val2)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == val1 || root->data == val2)
    {
        return root;
    }
    Node *l = lowestCommonAcc(root->left, val1, val2);
    Node *r = lowestCommonAcc(root->right, val1, val2);

    if (l != nullptr && r != nullptr)
    {
        return root;
    }
    if (l != nullptr)
        return l;
    if (r != nullptr)
        return r;

    return nullptr;
}
int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    drawBinaryTree(root);
    Inorder(root);
    cout << endl;

    Node *value = lowestCommonAcc(root, 9, 8);
    if (value != nullptr)
        cout << "LCA is" << (value->data);
    return 0;
}