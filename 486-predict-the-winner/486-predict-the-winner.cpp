class Solution {
public:
    int solve(vector<int> &n,int s,int e,vector<vector<int>>& dp)
    {
        if(s>e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int sum1,sum2;
        sum1=n[s]+min(solve(n,s+2,e,dp),solve(n,s+1,e-1,dp)); 
        sum2=n[e]+min(solve(n,s+1,e-1,dp),solve(n,s,e-2,dp));
        return dp[s][e]=max(sum1,sum2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int player1=solve(nums,0,n-1,dp);
        int player2=0;
        for(auto x:nums)
            player2+=x;
        player2-=player1;
        return player1>=player2;
    }
};