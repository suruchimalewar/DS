#include <iostream>
using namespace std;
/* A binary tree tNode has data, a pointer to left child 
and a pointer to right child */
struct TreeNode { 
	int data; 
	struct TreeNode* left; 
	struct TreeNode* right; 
}; 

/* Function to traverse the binary tree without recursion and 
without stack */
void MorrisTraversal(TreeNode* root) 
{ 
    TreeNode *prev = NULL, *cur;
    
    cur = root;
    
    while(cur != nullptr){
        if(cur->left == nullptr){
            cout << cur->data << " ";
            cur = cur->right;
        } else {
            //inorder predessor
            prev = cur->left;
            while(prev->right != nullptr && prev->right != cur)
                prev = prev->right;
            if(prev->right == nullptr){
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = nullptr;
                cout << cur->data << " ";
                cur = cur-> right;
            }
        }
    }
	
} 

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the 
given data and NULL left and right pointers. */
TreeNode* newtNode(int data) 
{ 
    TreeNode* node = new TreeNode(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return (node); 
} 

/* Driver program to test above functions*/
int main() 
{ 

	/* Constructed binary tree is 
			1 
		/ \ 
		2	 3 
	/ \ 
	4	 5 
*/
	TreeNode* root = newtNode(1); 
	root->left = newtNode(2); 
	root->right = newtNode(3); 
	root->left->left = newtNode(4); 
	root->left->right = newtNode(5); 

	MorrisTraversal(root); 

	return 0; 
} 
