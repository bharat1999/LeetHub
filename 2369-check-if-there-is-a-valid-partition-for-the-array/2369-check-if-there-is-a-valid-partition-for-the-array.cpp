class Solution {
    vector<int> dp;
    int n;
    bool solve(vector<int>& nums,int i)
    {
        if(i>=n)
            return true;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        bool ans = false;
        if(i+1<n)
        {
            if(nums[i]==nums[i+1])
                ans|=solve(nums,i+2);
        }
        if(i+2<n)
        {
            if(nums[i]==nums[i+1] and nums[i+1]==nums[i+2])
                ans|=solve(nums,i+3);
            if(nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1)
                ans|=solve(nums,i+3);
        }
        return dp[i] = ans;
    }
public:
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(nums,0);
    }
};