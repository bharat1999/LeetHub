class Solution {
    int solve(vector<vector<int>>& t,int i,int j,vector<vector<int>>& dp)
    {
        if(i == t.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = t[i][j] + min(solve(t,i+1,j,dp),solve(t,i+1,j+1,dp));
    }
public:
    int minimumTotal(vector<vector<int>>& t) 
    {
        int n = t.size();
        vector<vector<int>> dp(n,vector<int> (t[n-1].size(),-1));
        return solve(t,0,0,dp);
    }
};