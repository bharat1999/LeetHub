class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int n = 10001; // as max value of nums[i] = 10000
        int maxi=*max_element(nums.begin(),nums.end()); // so that loop will only run till required
        vector<int> sum(n, 0);
        vector<int> dp(n, 0);
        for(auto num: nums)
            sum[num] += num;
        dp[0] = 0;
        dp[1] = sum[1];
        for(int i=2; i<=maxi; i++)
            dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
        return dp[maxi];
    }
};