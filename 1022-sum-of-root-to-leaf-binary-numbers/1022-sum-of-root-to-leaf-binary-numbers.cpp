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
    void solve(TreeNode* &root,string &s,vector<int> &v)
    {
        if(!root)
            return;
        s.push_back(root->val+'0');
        if(!root->left and !root->right)
        {
            cout<<s<<" ";
            v.push_back(stoi(s,0,2));
            s.pop_back();
            return;
        }
        solve(root->left,s,v);
        solve(root->right,s,v);
        s.pop_back();
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        string s;
        solve(root,s,v);
        int sum=0;
        for(auto x:v)
            sum+=x;
        return sum;
    }
};