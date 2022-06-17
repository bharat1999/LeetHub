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
    void dfs(TreeNode* root, TreeNode* parent, int& steps){
        if(root == NULL) 
            return;
        dfs(root->left, root, steps);
        dfs(root->right, root, steps);
        if(parent != NULL)
        {
            // if root have extra give to parent till it become one
            if(root->val > 1)
            {
                while(root->val != 1)
                {
                    parent->val++;
                    root->val--;
                    steps++;
                }
            }
            // if root need than borrow from parent till become one
            else
            {
                while(root->val != 1)
                {
                    parent->val--;
                    root->val++;
                    steps++;
                }
            }   
        }
    }
public:
    int distributeCoins(TreeNode* root) {
        int steps = 0;
        TreeNode* parent = NULL;
        dfs(root, parent, steps);
        return steps;
    }
};