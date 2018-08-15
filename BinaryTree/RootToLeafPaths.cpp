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

void printVector(vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
}
void PrintRootToLeaf(Node *root, vector<int> v)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        v.push_back(root->data);
        printVector(v);
        cout << endl;
        v.pop_back();
        return;
    }
    v.push_back(root->data);
    PrintRootToLeaf(root->left, v);
    PrintRootToLeaf(root->right, v);
}

void PrintRootToLeafutil(Node *root)
{
    vector<int> vec;
    PrintRootToLeaf(root, vec);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Given a binary tree, print all root-to-leaf paths  \n";
    PrintRootToLeafutil(root);
}