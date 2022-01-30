class Solution {
    int solve(vector<vector<int>>& mat,int n,int i,int j,vector<vector<int>>& dp)
    {
        if(i==n)
            return 0;
        if(j<0 or j==n)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = mat[i][j] + min(solve(mat,n,i+1,j-1,dp),min(solve(mat,n,i+1,j,dp),solve(mat,n,i+1,j+1,dp)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> dp(n,vector<int> (n,-1));
            ans=min(ans,solve(matrix,n,0,i,dp));   
        }
        return ans;
    }
};