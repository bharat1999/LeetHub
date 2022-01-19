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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            bool isChild=false;
            int leftMost = q.front()->val;
            int n=q.size();
            while(n--)
            {
                auto f = q.front();
                if(f->left)
                {
                    isChild=true;
                    q.push(f->left);
                }
                if(f->right)
                {
                    isChild=true;
                    q.push(f->right);
                }
                q.pop();
            }
            if(!isChild)
                return leftMost;
        }
        return -1;
    }
};