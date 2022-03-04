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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        int i=0;
        q.push(root);
        while(!q.empty())
        {
            
            int n=q.size();
            vector<int> r(n);
            for(int j=0;j<n;j++)
            {
                TreeNode *x = q.front();
                q.pop();
                int cur = i%2==0?j:n-j-1;
                r[cur]= x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            i++;
            ans.push_back(r);

        }
    return ans;
    }   
};