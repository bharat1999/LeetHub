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
    unordered_map<TreeNode*,TreeNode*> p;
    void set(TreeNode* root,TreeNode* parent)
    {
        if(!root)
            return;
        p[root] = parent;
        set(root->left,root);
        set(root->right,root);
    }
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        dfs(root->right);
        if(root->val>1)
        {
            int x = root->val -1;
            p[root]->val+=x;
            root->val-=x;
            ans+=x;
        }
        if(root->val<1)
        {
            int x = 1 -root->val ;
            p[root]->val-=x;
            root->val-=x;
            ans+=x;
        }
    }
public:
    int distributeCoins(TreeNode* root) {
        set(root,NULL);
        dfs(root);
        return ans;
    }
};