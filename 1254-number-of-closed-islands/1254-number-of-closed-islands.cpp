class Solution {
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==1)
            return;
        grid[i][j]=1;
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // mark all linked to  corner lands as 1 bcz they can't be closed
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 or j==0 or i==n-1 or j==m-1) and grid[i][j]==0)
                    dfs(grid,i,j,n,m);
            }
        }
        int ans = 0;
        // finding all closed islands by dfs
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    dfs(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};