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

bool isMirrorTree(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    if ((root1->data == root2->data) &&
        isMirrorTree(root1->left, root2->right) &&
        isMirrorTree(root1->right, root2->left))
    {
        return true;
    }
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(9);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->right->left = new Node(9);

    //bool isSame = isMirrorTree(root1, root2);
    if (isMirrorTree(root1, root2))
        cout << "The given tree is a SumTree";
    else
        cout << "The given tree is not a SumTree";

    return 0;
}