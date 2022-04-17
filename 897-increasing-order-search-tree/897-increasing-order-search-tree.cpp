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
    TreeNode *r = new TreeNode(-1);
    TreeNode *t = r;
    void traverse(TreeNode* root)
    {    
        if(!root)
            return;
        traverse(root->left);
        t->right = new TreeNode(root->val);
        t=t->right;
        traverse(root->right);
    }   
public:
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        return r->right;
    }
};