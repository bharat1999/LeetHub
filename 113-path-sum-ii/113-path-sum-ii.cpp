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
    vector<vector<int>> ans;
    void solve(TreeNode* root,int curSum,int targetSum,vector<int> path)
    {
        if(!root)
            return;
        curSum+=root->val;
        path.push_back(root->val);
        if(!root->left and !root->right)
        {
            if(curSum==targetSum)
                ans.push_back(path);
            return;
        }
        solve(root->left,curSum,targetSum,path);
        solve(root->right,curSum,targetSum,path);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,0,targetSum,{});
        return ans;
    }
};