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
    vector<TreeNode*> v;
    void pre(TreeNode *root)
    {
        if(!root)
            return;
        v.push_back(root);
        pre(root->left);
        pre(root->right);
    }
public:
    void flatten(TreeNode* root) {
        pre(root);
        TreeNode *t = new TreeNode(-1);
        TreeNode *cur = t;
        for(auto x:v)
        {
            cur->right = x;
            x->left = NULL;
            cur = cur->right;
        }
        root = cur->right;
    }
};