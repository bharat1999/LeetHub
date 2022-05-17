/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q1,q2;
        q1.push(original);
        q2.push(cloned);
        while(!q1.empty())
        {
            int n=q1.size();
            while(n--)
            {
                auto cur1 = q1.front();
                auto cur2 = q2.front();
                q1.pop();
                q2.pop();
                if(cur1==target)
                    return cur2;
                // as both tree are same push in both
                if(cur1->left)
                {
                    q1.push(cur1->left);
                    q2.push(cur2->left);
                }
                if(cur1->right)
                {
                    q1.push(cur1->right);
                    q2.push(cur2->right);
                }
            }
        }
        return NULL;
    }
};