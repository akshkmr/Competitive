#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

class TreeNode {
    public:
        int value = 0; 
        TreeNode *left; 
        TreeNode * right; 

        TreeNode(int x) {
            this->value = x; 
            left = right = nullptr; 
        }
}; 

void mirror(TreeNode *curr) {
    if (curr == nullptr)
        return; 
    
    mirror(curr->left); 
    mirror(curr->right); 

    TreeNode *temp; 
    temp = curr->left; 
    curr->left = curr->right; 
    curr->right = temp; 
}

void inOrder(TreeNode* node) {
    if (node == nullptr)
        return; 
    inOrder(node->left); 
    cout << node -> value << " "; 
    inOrder(node->right); 
}

int main() {
    TreeNode *root = new TreeNode(12); 
    root->left = new TreeNode(7); 
    root->right = new TreeNode(1); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(10); 
    root->right->right = new TreeNode(5); 

    inOrder(root); 
    cout << endl; 
    mirror(root); 
    cout << endl; 
    inOrder(root);
}