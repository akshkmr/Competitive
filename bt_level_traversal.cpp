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

vector<vector<int>> traverse(TreeNode* root) {
    vector<vector<int>> result; 

    if (root == nullptr) 
        return result; 

    queue<TreeNode* > queue; 
    queue.push(root); 

    while(!queue.empty()) {
        int levelSize = queue.size(); 
        vector<int> currentLevel; 

        for (int i=0; i<levelSize; i++) {
            TreeNode* currentNode = queue.front(); 
            queue.pop(); 
            currentLevel.push_back(currentNode->value); 

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left); 
            }
            if (currentNode->right != nullptr) {
                queue.push(currentNode->right); 
            }
        }
        result.push_back(currentLevel); 
    }
    return result; 
}

int main() {
    TreeNode *root = new TreeNode(12); 
    root->left = new TreeNode(7); 
    root->right = new TreeNode(1); 
    root->left->left = new TreeNode(9); 
    root->right->left = new TreeNode(10); 
    root->right->right = new TreeNode(5); 

    vector<vector<int>> result = traverse(root); 

    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " "; 
        }
        cout << endl; 
    }
}