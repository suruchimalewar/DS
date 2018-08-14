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

void FirstNodePerLevel(Node *root, int i, int *max)
{
    if (root == nullptr)
        return;

    if (*max < i)
    {
        cout << root->data;
        *max = i;
    }
    FirstNodePerLevel(root->left, i + 1, max);

    FirstNodePerLevel(root->right, i + 1, max);
}

void leftViewUtil(Node *root)
{
    int max = 0;
    FirstNodePerLevel(root, 1, &max);
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(9);

    cout << "Left View of given Binary tree using recusion is  \n";
    leftViewUtil(root);
}
