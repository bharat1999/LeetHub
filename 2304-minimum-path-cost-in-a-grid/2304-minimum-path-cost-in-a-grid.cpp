class Solution {
    int dp[51][51];
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &cost)
    {
        if(i==grid.size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k=0;k<grid[0].size();k++)
        {
            ans = min(ans,grid[i][j] + cost[grid[i][j]][k] + solve(grid,i+1,k,cost));
        }
        return dp[i][j] = ans;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<grid[0].size();j++)
            ans = min(ans,solve(grid,0,j,moveCost));
        return ans;
    }
};