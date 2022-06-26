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
    void solve(TreeNode *root)
    {
        // if leaf or NULL
        if(!root or (!root->left and !root->right))
            return;
        // if root have left child
        if(root->left)
        {
            solve(root->left);
            //temporarily store right of root in tmp
            TreeNode *tmp = root->right;
            //make left of root as Null and right as left sol
            root->right=root->left;
            root->left = NULL;
            //search for rightmost child of right to join tmp
            TreeNode *cur = root;
            while(cur->right)
                cur=cur->right;
            cur->right = tmp;
        }
        solve(root->right);
    }
public:
    void flatten(TreeNode* root) {
        solve(root);
    }
};