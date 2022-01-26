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
    void preorder(TreeNode *root,vector<int> &res)
    {
        if(!root)
            return;
        preorder(root->left,res);
        res.push_back(root->val);
        preorder(root->right,res);
    }    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1,res2;
        preorder(root1,res1);
        preorder(root2,res2);
        int n=res1.size(),m=res2.size();
        vector<int> res(n+m);
        int i=n-1,j=m-1,k=m+n-1;
        while(i>=0 and j>=0)
        {
            if(res1[i]>res2[j])
                res[k--]=res1[i--];
            else
                res[k--]=res2[j--];
        }
        while(i>=0)
            res[k--]=res1[i--];
        while(j>=0)
            res[k--]=res2[j--];
        return res;
    }
};