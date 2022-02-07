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
     bool isSameTree(TreeNode* p, TreeNode* q)
     {
        // if both are NULL than true as equal
        if(!p and !q)
            return true;
        // if one of them is Null return false 
        if(!p or !q)
            return false;
        // check if both value is same and recursively check for left and right
        return p->val == q->val and isSameTree(p->left,q->left) and isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root)
            return false;
        // if root and subroot value same than check starting from same nodes
        // otherwise check from root->left and root->right
        return (root->val == subRoot->val and isSameTree(root, subRoot)) 
            or
            isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};