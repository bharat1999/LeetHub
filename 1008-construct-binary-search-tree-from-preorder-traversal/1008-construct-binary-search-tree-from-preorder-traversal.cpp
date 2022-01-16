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
    TreeNode* create(TreeNode*root ,int data)
    {
        if(!root)
            return new TreeNode(data);
        if(data<root->val)
            root->left=create(root->left,data);
        else
            root->right=create(root->right,data);
        return root;
    }
        
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size();
        TreeNode* root=NULL;
        for(auto x:pre)
            root=create(root,x);
        return root;
    }
};