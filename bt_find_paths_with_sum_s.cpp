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

void findPathsRecursive(TreeNode* currentNode, int sum, vector<int> &currentPath, vector<vector<int>> &allPaths) {
   
   if (currentNode == nullptr) 
       return; 

    currentPath.push_back(currentNode -> value); 

    if (currentNode->left == nullptr && currentNode->right == nullptr && currentNode->value == sum) {
        allPaths.push_back(currentPath); 
    }  

    findPathsRecursive(currentNode->left, sum - currentNode->value, currentPath, allPaths); 
    findPathsRecursive(currentNode->right, sum - currentNode->value, currentPath, allPaths);

    currentPath.pop_back();
}

vector<vector<int>> findPaths(TreeNode* root, int sum) {
    vector<vector<int>> allPaths; 
    vector<int> currentPath; 
    findPathsRecursive(root, sum, currentPath, allPaths); 
    return allPaths; 
}

int main() {
    TreeNode *root = new TreeNode(12); 
    root->left = new TreeNode(7); 
    root->right = new TreeNode(1); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(10); 
    root->right->right = new TreeNode(5); 

    vector<vector<int>> result = findPaths(root, 23); 

    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " "; 
        }
        cout << endl; 
    }
}