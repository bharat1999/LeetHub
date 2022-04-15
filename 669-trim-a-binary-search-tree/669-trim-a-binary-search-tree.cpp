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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        // if root val high than upper bound than all the right subtree will be higher
        if(root->val>high)
            return trimBST(root->left,low,high);        
        // if root val less than lower bound than all the left subtree will be smaller
        if(root->val<low)
            return trimBST(root->right,low,high);
        // otheriwse if root in range get left and right
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }   
};