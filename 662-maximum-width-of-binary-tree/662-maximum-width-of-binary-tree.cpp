class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        while (!q.empty()) 
        {
            int start = q.front().second, end = start; // end started same as start
            for (int i = 0, n = q.size(); i < n; i++) 
            {
                auto cur = q.front();
                end = cur.second;
                // this is to start each new level indexing from 0 to avoid overflow
                int idx = end - start;
                q.pop();
                if (cur.first->left) 
                    q.push({cur.first->left,(long long) idx * 2});
                if (cur.first->right) 
                    q.push({cur.first->right,(long long) idx * 2 + 1});
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};