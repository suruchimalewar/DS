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

void PrintInorder(Node *root)
{
    stack<Node *> s1;
    Node *curr = root;

    while (!s1.empty() || curr != nullptr)
    {
        while (curr != nullptr)
        {
            s1.push(curr);
            curr = curr->left;
        }
        curr = s1.top();
        s1.pop();

        cout << curr->data;
        curr = curr->right;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nInorder traversal of binary tree is \n";
    PrintInorder(root);
}