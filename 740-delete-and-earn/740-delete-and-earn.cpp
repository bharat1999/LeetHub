class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> sum(n,0);
        vector<int> dp(n,0);
        for(auto x:nums)
            sum[x]+=x;
        dp[0] = 0;
        dp[1] = sum[1];
        for(int i=2;i<n;i++)
        {
            // we either take current and one before adjacent or take adjacent one
            dp[i] = max(sum[i] + dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};