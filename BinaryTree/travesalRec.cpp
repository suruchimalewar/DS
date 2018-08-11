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

void printPreorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
void printPostorder(Node *root)
{
    if (root == nullptr)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
}