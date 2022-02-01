class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                    continue;
                // if first row their is only one way to reach their
                else if(i==0)
                    dp[i][j]=1;
                // if first col their is only one way to reach their
                else if(j==0)
                    dp[i][j]=1;
                // the way to reach i,j is the no of ways to reach from top + reach from left;
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};