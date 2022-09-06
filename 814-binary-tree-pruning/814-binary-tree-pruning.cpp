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
    bool solve(TreeNode *root)
    {
        if(!root)
            return false;
        bool flag = false;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(root->val==1)
            flag = true;
        if(!l)
            root->left = NULL;
        if(!r)
            root->right = NULL;
        return flag or l or r;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        if(!root->left and !root->right and root->val==0)
            return NULL;
        return root;
    }
};