class Solution {
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid,i+1,j) + dfs(grid,i,j+1) + dfs(grid,i-1,j) + dfs(grid,i,j-1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int t;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1 and(i==0 or j==0 or i==n-1 or j==m-1))
                    t=dfs(grid,i,j);
        int count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                {
                    count+=dfs(grid,i,j);
                }
        return count;            
    }
};