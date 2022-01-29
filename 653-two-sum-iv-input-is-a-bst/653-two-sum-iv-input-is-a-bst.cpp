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
    vector<int> nodes;
    void inOrder(TreeNode *root)
    {
        if(!root)
            return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int s = 0,e = nodes.size()-1;
        while(s<e)
        {
            if(nodes[s]+nodes[e]==k)
                return true;
            if(nodes[s]+nodes[e]<k)
                s++;
            else
                e--;
        }
        return false;
    }
};