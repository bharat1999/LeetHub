/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans;
    void solve(TreeNode* root,int d)
    {
        if(!root)
            return;
        if(root->val == d)
        {
            ans = root;
            return;
        }
        solve(root->left,d);
        solve(root->right,d);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int d = target->val;
        solve(cloned,d);
        return ans;
    }
};