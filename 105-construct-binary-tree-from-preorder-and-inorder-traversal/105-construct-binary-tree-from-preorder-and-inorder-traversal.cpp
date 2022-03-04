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
    
    int i=0;
    TreeNode* buildTreeInAndPre(vector<int> pre,vector<int> in,int inS, int inE) 
    {
	    if (inS>inE) 
		    return NULL;
        
	    TreeNode* root = new TreeNode(pre[i++]);
	    int k = -1;
	    for (int j = inS ; j <= inE; j++) 
        {
		    if (in[j] == root->val) 
            {
			    k = j;
			    break;
		    }
	    }

	    root->left = buildTreeInAndPre(pre,in,inS, k - 1);
	    root->right = buildTreeInAndPre(pre,in,k + 1, inE);

	    return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = buildTreeInAndPre(preorder,inorder,0,inorder.size()-1);
        return root;
    }
};