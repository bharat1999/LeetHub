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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val>key)
            root->left = deleteNode(root->left,key);
        else if(root->val<key)
            root->right = deleteNode(root->right,key);
        else
        {
            // if leaf node
            if(!root->right and !root->left)
                return NULL;
            //if only 1 child
            if(!root->left and root->right)
                return root->right;
            if(root->left and !root->right)
                return root->left;
            // if 2 child
            TreeNode* replace = root->right;
            while(replace->left)
                replace = replace->left;
            root->val = replace->val;
            root->right = deleteNode(root->right,replace->val);
        }
        return root;
    }       
};