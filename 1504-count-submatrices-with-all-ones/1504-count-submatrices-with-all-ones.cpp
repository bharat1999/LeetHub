class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int  n=mat[0].size();
        
        vector<vector<int>> dp( m , vector<int>(n ));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    dp[i][j]=mat[i][j];
                }
                else
                {
                    if(mat[i][j]==0)
                    {
                        dp[i][j]=0;
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1] + 1;
                    }
                }
            }
        }
        int res=0;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                int  min_val=dp[i][j];
                for(int k=i;k>=0;k--)
                {
                    min_val=min(min_val , dp[k][j]);
                    
                    if(min_val==0)
                    {
                        break;
                    }
                    
                    res+=min_val;
                }
            }
        }
        
        return res;
    }
};