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
    int ans = 0;
    int freq[10];
    void solve(TreeNode* root,int len)
    {
        if(!root)
            return;
        freq[root->val]++;
        if(!root->left and !root->right)
        {
            bool palindrome = true;
            // if even length path
            if(len%2==0)
            {
                for(int i=1;i<=9;i++)
                {
                    if(freq[i]!=0 and freq[i]%2)
                    {
                        palindrome = false;
                        break;
                    }
                }
            }
            // length is odd so we need one element with odd freq
            else
            {
                bool odd = false;
                for(int i=1;i<=9;i++)
                {                    
                    if(freq[i]!=0 and freq[i]%2)
                    {
                        if(!odd)
                            odd = true;
                        else
                        {
                            palindrome = false;
                            break;
                        }
                    }
                }
            }
            if(palindrome)
                    ans++;
            freq[root->val]--;
            return; 
        }
        solve(root->left,len+1);
        solve(root->right,len+1);
        freq[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root,1);
        return ans;
    }
};