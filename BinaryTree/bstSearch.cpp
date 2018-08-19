#include "BinaryTree.h"
#include "BST.h"
#include <iostream>

using namespace std;
Node *SearchNode(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == val)
    {
        return root;
    }
    if (root->data >= val)
    {
        return SearchNode(root->left, val);
    }

    return SearchNode(root->right, val);
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
    cout << endl;

    Node *temp = SearchNode(root, 49);

    cout << "found node" << temp->data;

    return 0;
}
