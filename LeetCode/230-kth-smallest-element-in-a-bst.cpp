#include <iostream>
#include <stack>
#include <vector>
#include <queue>

// https://leetcode.com/problems/basic-calculator/discuss/1457045/C%2B%2B-oror-Explained-oror-Stacks-oror-Beginner-FriendlyEasy-To-Understand




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std; 

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq; 
        queue<TreeNode* > q; 
        q.push(root); 
        
        while (!q.empty()) {
            TreeNode* temp = q.front(); 
            q.pop(); 
            pq.push(temp->val); 
            
            if (pq.size() > k) {
                pq.pop(); 
            }
            
            if (temp->left != nullptr) {
                q.push(temp->left); 
            }
            
            if (temp->right != nullptr) {
                q.push(temp->right); 
            }
        }
        
        return pq.top(); 
    }