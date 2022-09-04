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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            map<int,vector<int>> mp1;
            int n = q.size();
            while(n--)
            {
                auto [r,c] = q.front();
                q.pop();
                mp1[c].push_back(r->val);
                if(r->left)
                    q.push({r->left,c-1});
                if(r->right)
                    q.push({r->right,c+1});
            }
            for(auto x:mp1)
            {
                sort(x.second.begin(),x.second.end());
                for(auto y:x.second)
                    mp[x.first].push_back(y);
            }
        }
        for(auto x:mp)
            ans.push_back(x.second);
        return ans;
    }
};