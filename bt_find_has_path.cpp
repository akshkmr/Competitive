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

bool hasPath(TreeNode* root, int sum) {
    if (root == nullptr)
        return false; 

    if (root->left == nullptr && root->right == nullptr && root->value==sum) {
        return true; 
    }

    return hasPath(root->left, sum-root->value) || hasPath(root->right, sum-root->value); 
        
}

int main() {
    TreeNode *root = new TreeNode(12); 
    root->left = new TreeNode(7); 
    root->right = new TreeNode(1); 
    root->left->left = new TreeNode(9); 
    root->right->left = new TreeNode(10); 
    root->right->right = new TreeNode(5); 

    cout << hasPath(root, 16) << endl; 
}