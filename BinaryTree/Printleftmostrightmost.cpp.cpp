#include "BinaryTree.h"
#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;
void extreamLeftAndRight(Node *root)
{
    if (root == nullptr)
        return;
    std::queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    cout << root->data;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp != nullptr)
        {
            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(root->right);

            if (!q.empty() && q.front() == nullptr)
                q.push(nullptr);
        }
        else if (!q.empty())
        {
            Node *temp2 = q.front();
            cout << temp2->data << " ";
            q.pop();
            while (q.front() != nullptr)
            {
                cout << "ok";
                Node *temp3 = q.front();
                q.pop();
                if (q.front() == nullptr)
                {
                    cout << temp3->data << " ";
                }
            }
        }
    }
}
int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    // Inorder(root);
    extreamLeftAndRight(root);
    cout << endl;

    return 0;
}
