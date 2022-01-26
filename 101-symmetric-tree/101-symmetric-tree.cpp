/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* left,TreeNode* right)
    {
        if(!left and !right) // if both are NULL than true
            return true; 
        if(!left or !right) // if one of left and right is null than its false
            return false;
        if(left->val!=right->val) // if value is not equal than false
            return false;
        // than check for both possible answer and than their AND
        return solve(left->left,right->right) and solve(right->left,left->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return solve(root->left,root->right);
        
    }
};