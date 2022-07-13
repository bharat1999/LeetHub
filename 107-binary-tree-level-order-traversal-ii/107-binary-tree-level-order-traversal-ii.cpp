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
    void solve(queue<TreeNode*>q)
    {
        if(q.empty())
            return;
        vector<int> tmp;
        int n = q.size();
        while(n--)
        {
            auto f = q.front();
            q.pop();
            tmp.push_back(f->val);
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
        solve(q);
        ans.push_back(tmp);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        solve(q);
        return ans;
    }
};