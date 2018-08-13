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

void finMinAndMax(Node *root, int *min, int *max, int hd)
{
    if (root == nullptr)
        return;

    if (*min > hd)
        *min = hd;
    else if (*max < hd)
        *max = hd;

    finMinAndMax(root->left, min, max, hd - 1);
    finMinAndMax(root->right, min, max, hd + 1);
}

void PrintVertical(Node *root, int i, int hd)
{
    if (root == nullptr)
        return;

    if (i == hd)
        cout << root->data << " ";

    PrintVertical(root->left, i, hd - 1);
    PrintVertical(root->right, i, hd + 1);
}

void printVerticalutil(Node *root)
{
    if (root == nullptr)
        return;

    int min = 0;
    int max = 0;
    finMinAndMax(root, &min, &max, 0);

    for (int i = min; i <= max; i++)
    {
        PrintVertical(root, i, 0);
        cout << endl;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Vertical view of given Binary tree is  \n";

    printVerticalutil(root);
    return 0;
}