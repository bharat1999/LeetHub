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
    TreeNode *prev=NULL,*first=NULL,*second=NULL;
    void inorder(TreeNode* root)
    {
        if(!root)
            return ;
        inorder(root->left);
        if(prev and root->val<prev->val)
        {
            // if first null means this is the first element out of order
            if(!first)
                first=prev;
            // this is the second to be out of order
            second=root;
        }
        prev=root;
        inorder(root->right);
    }
    public:
        void recoverTree(TreeNode* root) 
        {
            inorder(root);
            swap(first->val,second->val);
        }
};