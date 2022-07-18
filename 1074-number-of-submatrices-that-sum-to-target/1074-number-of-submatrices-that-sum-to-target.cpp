class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
        int r = m.size();
        int c = m[0].size();
        int dp[r+1][c+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(i==1)
                    dp[i][j]=m[i-1][j-1] + dp[i][j-1];
                else if(j==1)
                    dp[i][j] = m[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = m[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }      
        int ans = 0;
        for(int sr=1;sr<=r;sr++)
        {
            for(int er=sr;er<=r;er++)
            {
                for(int sc=1;sc<=c;sc++)
                {
                    for(int ec=sc;ec<=c;ec++)
                    {
                        long long sum = dp[er][ec] - dp[er][sc-1] - dp[sr-1][ec] + dp[sr-1][sc-1];    
                        if(sum==target)
                        {
                            ans++;
                        }
                    }
                }
            }
        }    
        return ans;
    }
};