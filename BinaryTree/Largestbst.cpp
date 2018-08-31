#include "BinaryTree.h"
#include "BST.h"
#include <iostream>

using namespace std;
struct Info
{
    bool isBST;
    int size;
    int min;
    int max;
};

Info largestBst(Node *root)
{
    Info info;
    if (root == nullptr)
    {
        info.isBST = true;
        info.size = 0;
        info.min = INT32_MAX;
        info.max = INT32_MIN;

        return info;
    }

    Info Left = largestBst(root->left);
    Info Right = largestBst(root->right);
    //for debugging
    //cout << root->data << " " << Left.max << " " << Right.min << endl;

    if (Left.isBST == true && Right.isBST == true &&
        Left.max < root->data && root->data <= Right.min)
    {
        info.isBST = true;
        info.size = Left.size + Right.size + 1;

        info.min = Left.size == 0 ? root->data : Left.min;
        info.max = Right.size == 0 ? root->data : Right.max;

        return info;
    }

    info.isBST = false;
    info.size = max(Left.size, Right.size);

    return info;
}
int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;
    Info info = largestBst(root);
    cout << info.size;
    if (info.isBST)
    {
        cout << "Given bst is a binary Tree";
    }
    else

        cout << "Given bst not is a binary Tree";
    return 0;
}
