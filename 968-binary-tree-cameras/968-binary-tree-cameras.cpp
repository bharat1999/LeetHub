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
    //States
    // needCover  Means node not obsere=ved
    // notNeeded  Means node is observed
    // hasCamera  Means node have camera
    public:
    string dfs(TreeNode* node, int &ans) 
    {
        if (node == NULL)
            return "notNeeded";    
        string left = dfs(node->left, ans);
        string right = dfs(node->right, ans);
        // if any child need cover put camera on parent
        if (left == "needCover" or right == "needCover") 
        {
            ans++;
            return "hasCamera";
        }
        // if any child has camera means root is observed no need to put camera
        else if (left == "hasCamera" || right == "hasCamera")
            return "notNeeded";
        // else root is leaf node that means it need cover
        else
            return "needCover";
    }
    
    int minCameraCover(TreeNode* root) {
        int ans = 0;
		
		// what if there's just one element
        if (dfs(root, ans) == "needCover")
            ans++;
			
        return ans;
    }
};