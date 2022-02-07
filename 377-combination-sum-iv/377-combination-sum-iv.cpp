class Solution {
    int solve(vector<int>& nums,int target,int n,vector<int>& dp)
    {
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int X=0;
        for(int i=0;i<n;i++)
        {
            //taking current number
            if(target>=nums[i])
                X+=solve(nums,target-nums[i],n,dp); 
        }
        return dp[target]=X;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return solve(nums,target,n,dp);
    }
};