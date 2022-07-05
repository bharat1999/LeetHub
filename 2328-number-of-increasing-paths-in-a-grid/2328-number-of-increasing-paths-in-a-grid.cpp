class Solution {
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int r,c;
    int solve(vector<vector<int>> &g,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0,op3=0,op4=0;
        if(i+1<r and g[i+1][j]>g[i][j])
            op1 = 1+solve(g,i+1,j);
        if(j+1<c and g[i][j+1]>g[i][j])
            op2 = 1+solve(g,i,j+1);
        if(i-1>=0 and g[i-1][j]>g[i][j])
            op3 = 1+solve(g,i-1,j);
        if(j-1>=0 and g[i][j-1]>g[i][j])
            op4 = 1+solve(g,i,j-1);
        // max with 1 bcz alone element is atleast 1
        return dp[i][j]=(op1+op2+op3+op4)%mod;
            
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        dp.resize(r,vector<int> (c,-1));
        int ans= 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans+=solve(grid,i,j);
                ans%=mod;
            }
        }
        // bcz single element is also strictly increasing
        return ans+(r*c);
    }
};