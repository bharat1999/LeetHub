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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(!q1.empty())
        {
            q2=q1;
            int n = q1.size();
            while(n--)
            {
                auto cur = q1.front();
                q1.pop();
                if(cur->left)
                    q1.push(cur->left);
                if(cur->right)
                    q1.push(cur->right);
            }
        }
        int sum=0;
        while(!q2.empty())
        {
            auto cur = q2.front();
            q2.pop();
            sum+=cur->val;
        }
        return sum;
    }
};