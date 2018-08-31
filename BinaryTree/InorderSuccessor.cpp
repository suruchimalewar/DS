#include "BinaryTree.h"
#include "BST.h"
#include <iostream>

using namespace std;
Node *Successor(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    Node *parent = nullptr;
    Node *curr = root;

    while (curr->data != val)
    {
        if (curr->data > val)
        {
            parent = curr;
            if (curr->left == nullptr || curr->data == val)
                break;
            curr = curr->left;
        }
        else
        {
            if (root->right == nullptr || curr->data == val)
                break;
            curr = curr->right;
        }
    }
    if (curr->data != val)
        return nullptr;

    if (curr->right == nullptr)
        return parent;

    curr = curr->right;
    while (curr->left != nullptr)
        curr = curr->left;

    return curr;
}
int main()
{
    // Variation 2
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    Node *temp = Successor(root, 14);
    if (temp != nullptr)
        cout << temp->data;
    else
        cout << "null";
    return 0;
}
