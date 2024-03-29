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
    int ans = 0;
    void traverse(TreeNode* root,int mx)
    {
        if(!root)
            return;
        if(root->val>=mx)
            ans++;
        mx=max(mx,root->val);
        traverse(root->left,mx);
        traverse(root->right,mx);
        
    }
public:
    int goodNodes(TreeNode* root) {
        traverse(root,INT_MIN);
        return ans;
    }
};