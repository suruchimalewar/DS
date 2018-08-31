#include "BinaryTree.h"
#include "BST.h"
#include <stack>
#include <iostream>

using namespace std;

typedef stack<Node *> Stack;

void helper(Stack &s1, Stack &s2, bool flag)
{
    Node *c1 = s1.top();
    cout << c1->data << " ";

    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();

        if (flag)
        {
            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }
        else
        {
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
    }
}
void etreamAlternative(Node *root)
{
    if (root == nullptr)
        return;
    std::stack<Node *> s1;
    std::stack<Node *> s2;
    s1.push(root);
    //static int
    while (!s1.empty() || !s2.empty())
    {
        helper(s1, s2, false);
        helper(s2, s1, true);
    }
}
int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;
    etreamAlternative(root);
    return 0;
}
