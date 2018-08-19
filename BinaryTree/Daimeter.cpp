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

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int heightOfBinaryTree(Node *root, int *res)
{
    if (root == nullptr)
    {
        return 0;
    }

    int l = heightOfBinaryTree(root->left, res);
    int r = heightOfBinaryTree(root->right, res);

    //*res = max(*res, l + r + 1);
    //return 1 + max(l, r);

    if (l > r)
    {
        if (l + r + 1 >= *res)
            *res = l + 1 + r;
        return l + 1;
    }

    else
    {
        if (r + l + 1 >= *res)
            *res = r + 1 + l;
        return r + 1;
    }
}

int Dimeter(Node *root)
{

    int Max1 = 0;
    int x = heightOfBinaryTree(root, &Max1);
    return Max1 + 1;
}

// void daimeter(Node *root)
// {
//     if (root == nullptr)
//         return;

//     int tmp = 1 + height(root->left) + height(root->right);
//     Max = max(Max, tmp);

//     daimeter(root->left);
//     daimeter(root->right);
// }
int main()
{
    int res = 0;
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    // root->left->left->left = new Node(4);
    // root->left->left->right = new Node(5);
    // root->left->left->right->left = new Node(1);
    // root->left->left->right->left->right = new Node(2);
    // root->left->right = new Node(4);
    // root->left->right->right = new Node(3);
    // root->left->right->right->left = new Node(6);
    // root->left->right->right->right = new Node(7);
    // root->left->right->right->right->left = new Node(8);
    // root->right = new Node(5);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    heightOfBinaryTree(root, &res);
    //daimeter(root);
    printf("Diameter of the given binary tree is %d\n", res);

    getchar();
    return 0;
}