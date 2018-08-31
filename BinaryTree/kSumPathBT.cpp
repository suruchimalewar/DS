#include "BinaryTree.h"
#include "BST.h"
#include <iostream>
#include <vector>

typedef std::vector<int> Vector;

using namespace std;
void printVector(Vector &v, int pos)
{
    for (int i = pos; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void kSumPath(Node *root, Vector &v, int k)
{
    if (root == nullptr)
        return;

    v.push_back(root->data);

    kSumPath(root->left, v, k);
    kSumPath(root->right, v, k);

    int result = 0;
    for (int j = v.size() - 1; j >= 0; j--)
    {
        //cout << result << endl;
        result = result + v[j];
        if (result == k)
        {
            // /cout << "ok";
            printVector(v, j);
        }
    }
    v.pop_back();
}
int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;
    Vector v1;
    kSumPath(root, v1, 3);

    return 0;
}
