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

int traverse(TreeNode* root) {
    int minDepth = 0; 
    queue<TreeNode* > queue; 
    queue.push(root); 

    while(!queue.empty()) {
        minDepth++; 
        int levelSize = queue.size(); 

        for (int i=0; i<levelSize; i++) {
            TreeNode* currentNode = queue.front(); 
            queue.pop(); 

            if (currentNode -> left == nullptr && currentNode -> right == nullptr) {
                return minDepth; 
            }

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left); 
            }
            if (currentNode->right != nullptr) {
                queue.push(currentNode->right); 
            }
        }
    }
    return minDepth; 
}

int main() {
    TreeNode *root = new TreeNode(12); 
    root->left = new TreeNode(7); 
    root->right = new TreeNode(1); 
    root->left->left = new TreeNode(9); 
    root->right->left = new TreeNode(10); 
    root->right->right = new TreeNode(5); 

    int result = traverse(root); 
    cout << result << endl; 
}