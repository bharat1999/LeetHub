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
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return "";
        if(!root->left and !root->right)
            return to_string(root->val);
        if(!root->right)
            return to_string(root->val)+"("+tree2str(root->left)+")";
        //if right is not null an dleft can be any we go to both
        // as even if left is null we have to add () to ans
        return to_string(root->val)+"("+tree2str(root->left)+")("+tree2str(root->right)+")";   
        
    }
};