class Solution {
    int dp[1005][1005];
    int solve(int s,vector<int>&nums ,vector<int>&mul,int i)
    {
        if(i==mul.size())
            return 0;
        if(dp[s][i]!=INT_MIN)
            return dp[s][i];
        int startAns = mul[i]*nums[s] + solve(s+1,nums,mul,i+1);
        int e = (nums.size()-1) - (i - s);
        int endAns = mul[i]*nums[e] + solve(s,nums,mul,i+1);
        return dp[s][i] = max(startAns,endAns);
        
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        for(int i=0;i<1005;i++)
            for(int j=0;j<1005;j++)
                dp[i][j]=INT_MIN;
        return solve(0,nums,multipliers,0);
        
    }
};