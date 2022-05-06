#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recur(TreeNode* root, string path, vector<string> &ans) {
    if (root == nullptr) 
        return; 
    
    if (root->left == nullptr && root->right==nullptr) {
        path += to_string(root->val); 
        ans.push_back(path);  
    }
    
    recur(root->left, path + to_string(root->val) + "->", ans); 
    recur(root->right, path + to_string(root->val) + "->", ans); 
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans; 
    recur(root, "", ans); 
    return ans; 
}

int main() {
    
}