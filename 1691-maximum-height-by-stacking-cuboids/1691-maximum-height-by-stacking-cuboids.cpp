class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        int n = c.size();
        
        for(auto &x : c){
            sort(x.begin(), x.end());
        }
        
        sort(c.begin(), c.end());
        
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i] = c[i][2];
            ans = max(ans, dp[i]);
            for(int j = 0; j < i; j++)
            {
                if(c[i][1] >= c[j][1] and c[i][2] >= c[j][2])
                    dp[i] = max(dp[i], dp[j] + c[i][2]);
                ans = max(ans, dp[i]);
            }
        }
        
        return ans;
        
    }
};